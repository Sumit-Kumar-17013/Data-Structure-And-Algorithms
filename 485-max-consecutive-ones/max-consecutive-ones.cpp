class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxNum = 0;
        // tc = O(n)

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(nums[i] == 1)
            {
                count++;
                maxNum = max(maxNum , count);
            }
            else
            {
                count = 0;
            }
        }
        return maxNum;
    }
};