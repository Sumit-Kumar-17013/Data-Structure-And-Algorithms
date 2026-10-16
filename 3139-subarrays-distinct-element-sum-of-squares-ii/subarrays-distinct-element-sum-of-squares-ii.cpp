
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        //  tc : O(nlogn)
        const long long MOD = 1e9 + 7;
        int n = nums.size();

        vector<long long> tree(4 * n, 0);
        vector<long long> lazy(4 * n, 0);

        auto update = [&](auto&& self, int node, int start, int end,
                          int l, int r, long long val) -> void {
            if (l > end || r < start) return;

            if (l <= start && end <= r) {
                tree[node] = (tree[node] + 2 * val * 0LL) % MOD;
                lazy[node] = (lazy[node] + val) % MOD;
                return;
            }

            int mid = (start + end) / 2;
            self(self, node * 2, start, mid, l, r, val);
            self(self, node * 2 + 1, mid + 1, end, l, r, val);
        };

        vector<long long> sum(4 * n, 0), sq(4 * n, 0);
        vector<long long> add(4 * n, 0);

        auto apply = [&](int node, int len, long long val) {
            sq[node] = (sq[node] + 2 * val % MOD * sum[node] % MOD
                        + val * val % MOD * len % MOD) % MOD;
            sum[node] = (sum[node] + val * len) % MOD;
            add[node] = (add[node] + val) % MOD;
        };

        auto push = [&](int node, int l, int r) {
            if (add[node] == 0 || l == r) return;
            int mid = (l + r) / 2;
            apply(node * 2, mid - l + 1, add[node]);
            apply(node * 2 + 1, r - mid, add[node]);
            add[node] = 0;
        };

        auto updateRange = [&](auto&& self, int node, int l, int r,
                               int ql, int qr, long long val) -> void {
            if (ql > r || qr < l) return;

            if (ql <= l && r <= qr) {
                apply(node, r - l + 1, val);
                return;
            }

            push(node, l, r);
            int mid = (l + r) / 2;

            self(self, node * 2, l, mid, ql, qr, val);
            self(self, node * 2 + 1, mid + 1, r, ql, qr, val);

            sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
            sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
        };

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = last.count(nums[i]) ? last[nums[i]] + 1 : 0;

            updateRange(updateRange, 1, 0, n - 1, left, i, 1);

            last[nums[i]] = i;
            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};
