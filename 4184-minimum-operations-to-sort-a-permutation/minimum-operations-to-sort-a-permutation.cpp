class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> rev(nums.rbegin(), nums.rend());

        auto isSortedRotation = [&](vector<int>& arr, int k) {
            for (int i = 0; i < n; i++) {
                if (arr[(k + i) % n] != i)
                    return false;
            }
            return true;
        };

        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        int k0 = zero;
        int k1 = (n - 1 - zero + n) % n;

        bool normal = isSortedRotation(nums, k0);
        bool reversed = isSortedRotation(rev, k1);

        if (!normal && !reversed)
            return -1;

        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int, int>> q;

        dist[0][0] = 0;
        q.push({0, 0});

        while (!q.empty()) {
            auto [orientation, k] = q.front();
            q.pop();

            int d = dist[orientation][k];

            int nk = (k + 1) % n;

            if (dist[orientation][nk] == -1) {
                dist[orientation][nk] = d + 1;
                q.push({orientation, nk});
            }

            int no = 1 - orientation;
            nk = (n - k) % n;

            if (dist[no][nk] == -1) {
                dist[no][nk] = d + 1;
                q.push({no, nk});
            }
        }

        int ans = INT_MAX;

        if (normal)
            ans = min(ans, dist[0][k0]);

        if (reversed)
            ans = min(ans, dist[1][k1]);

        return ans == INT_MAX ? -1 : ans;
    }
};