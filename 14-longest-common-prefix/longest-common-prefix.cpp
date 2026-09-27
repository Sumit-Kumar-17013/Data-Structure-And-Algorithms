class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minLen = strs[0].size();

        for(int i = 0 ; i < n - 1 ; i++)
        {
            string first = strs[i];
            string second = strs[i + 1];

            int j = 0;
            int len = min(strs[i].size(), strs[i + 1].size());

            while( j < len)
            {
                if(strs[i][j] != strs[i + 1][j])
                {
                    break;
                }
                j++;
            }

            minLen = min(minLen , j);
        }

        return strs[0].substr(0 , minLen);
    }
};