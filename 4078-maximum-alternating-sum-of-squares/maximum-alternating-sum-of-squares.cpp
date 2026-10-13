class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long n = nums.size();
        vector<long long> squ(n);

        for(int i = 0 ; i  < n ; i++)
        {
            squ[i] = nums[i] * nums[i];
        }

        sort(squ.begin() , squ.end());

        long long score = 0;

        for (int i = 0; i < n / 2; i++)
        {
            score -= squ[i];
        }

        for(int i = n / 2  ; i <n ; i++)
        {
            score += squ[i];
        }

        return score;
    }
};