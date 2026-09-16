class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // TC = O(log n)
        int n = nums.size();
        sort(nums.begin() , nums.end());

        int maxSum = 0;
        for(int i = 0 ; i < n ; i +=2)
        {
            maxSum += nums[i];
        }
        return maxSum;
    }
};