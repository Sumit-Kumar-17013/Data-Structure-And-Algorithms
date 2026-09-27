class Solution {
public:
    int strStr(string haystack, string needle) {
        // Tc = O(n * m)
        int n = haystack.size();
        int m = needle.size();

        if(n < m)
        {
            return -1;
        }

        for(int i = 0 ; i < n ; i++)
        {
            int j = 0;

            while((i + j) < n  && j < m)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
                j++;
            }

            if(j == m)
            {
                return i;
            }
        }

        return -1;

    }
};