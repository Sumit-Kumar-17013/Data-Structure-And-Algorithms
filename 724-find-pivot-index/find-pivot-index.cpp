class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //  TC = O(n)

        int n = nums.size();
        int Rightsum = 0;

        for(int i = 0 ; i < n ; i++)
        {
            Rightsum += nums[i];
        }

        int Leftsum = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(Leftsum == Rightsum - nums[i])
            {
                return i;
            }

            Leftsum += nums[i];
            Rightsum -= nums[i];
        }

        return -1;
    }
};