class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //  TC = O(n)
        int n = nums.size();
         set<int> s;

        for(int num : nums)
        {
            s.insert(num);
        }

        vector<int> res;

        for(int i = 1 ; i <= n ; i++)
        {
            if(s.find(i) == s.end())
            {
                res.push_back(i);
            }
        }

        return res;
    }
};