class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> result(n);

        for(int i = 0 ; i < n ; i++)
        {
            result[i] = nums[i];
        }

        sort(result.begin() , result.end() , [](int val1 , int val2)
        {
            return val1 % 2 < val2 % 2;
        });

        for(int i = 0 ; i < n ; i++)
        {
            nums[i] = result[i];
        }

        return nums;
    }
};