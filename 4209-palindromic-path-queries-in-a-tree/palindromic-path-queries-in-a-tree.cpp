class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> tin(n), tout(n), depth(n);
        vector<vector<int>> up(17, vector<int>(n));
        vector<int> pref(n);
        int timer = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = timer++;
            up[0][u] = p;

            for (int k = 1; k < 17; k++)
                up[k][u] = up[k - 1][up[k - 1][u]];

            for (int v : adj[u]) {
                if (v == p) continue;

                depth[v] = depth[u] + 1;
                pref[v] = pref[u] ^ (1 << (s[v] - 'a'));
                dfs(v, u);
            }

            tout[u] = timer - 1;
        };

        pref[0] = 1 << (s[0] - 'a');
        dfs(0, 0);

        vector<int> bit(n + 1);

        auto add = [&](int i, int val) {
            for (i++; i <= n; i += i & -i)
                bit[i] ^= val;
        };

        auto get = [&](int i) {
            int res = 0;
            for (i++; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        };

        auto updateSubtree = [&](int u, int delta) {
            add(tin[u], delta);
            if (tout[u] + 1 < n)
                add(tout[u] + 1, delta);
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];
            for (int k = 0; k < 17; k++)
                if (diff & (1 << k))
                    u = up[k][u];

            if (u == v) return u;

            for (int k = 16; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        vector<bool> ans;

        for (auto& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int delta = (1 << (s[u] - 'a')) ^
                            (1 << (c - 'a'));

                updateSubtree(u, delta);
                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);
                int pu = pref[u] ^ get(tin[u]);
                int pv = pref[v] ^ get(tin[v]);

                int mask = pu ^ pv ^ (1 << (s[w] - 'a'));

                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};