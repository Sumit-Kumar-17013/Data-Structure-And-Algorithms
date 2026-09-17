class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // DC
        // TC = o(n)
        int n = arr.size();

        vector<int> dp(n, INT_MAX);
        
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && dp[left - 1] != INT_MAX) {
                    ans = min(ans, len + dp[left - 1]);
                }
            }

            if (right > 0) {
                dp[right] = dp[right - 1];
            }

            if (sum == target) {
                int len = right - left + 1;
                dp[right] = min(dp[right], len);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};