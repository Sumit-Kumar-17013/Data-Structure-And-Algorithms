class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26 , 0);
        // Tc = o(n)

        for(char c : s)
        {
            int idx = c - 'a';
            freq[idx]++;
        }

        for(char c : t)
        {
            int idx = c - 'a';
            freq[idx]--;
        }

        for(int i = 0 ; i < 26 ; i++)
        {
            if(freq[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};