class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool sortable = true;
            int prevMax = 0;

            for (int start = 0; start < n; start += k) {
                int mn = INT_MAX;
                int mx = INT_MIN;
                int descents = 0;

                for (int j = start; j < start + k; j++) {
                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);

                    int next = (j + 1 < start + k)
                                   ? nums[j + 1]
                                   : nums[start];

                    if (nums[j] > next)
                        descents++;
                }

                if (descents > 1 || (start > 0 && prevMax > mn)) {
                    sortable = false;
                    break;
                }

                prevMax = mx;
            }

            if (sortable)
                ans += k;
        }

        return ans;
    }
    
};