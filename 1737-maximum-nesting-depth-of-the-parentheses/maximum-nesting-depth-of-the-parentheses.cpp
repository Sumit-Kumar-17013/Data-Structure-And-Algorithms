class Solution {
public:
    int maxDepth(string s) {
        // tc = O(n)
        int n = s.size();
        int curropen = 0;
        int maxopen = 0;

        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '(')
            {
                curropen++;
            }
            else if(s[i] == ')')
            {
                curropen--;
            }
            maxopen = max(maxopen , curropen);
        }
        return maxopen;
    }
};