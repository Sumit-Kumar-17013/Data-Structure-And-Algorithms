class Solution {
public:
    int reverseDegree(string s) {
        // TC = O(n)
        int ans = 0;

        for(int i = 0 ; i < s.size() ; i++)
        {
            int normalpos = s[i] - 'a' + 1;
            int reversepos = 27 - normalpos;

            ans += reversepos * (i  + 1);
        }

        return ans;
    }
};