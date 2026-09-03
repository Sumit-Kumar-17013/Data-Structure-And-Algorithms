class Solution {
public:
    vector<int> intersect(vector<int>& num1, vector<int>& num2) {
        int freq[1001] = {0};

        for(int num : num1)
        {
            freq[num]++;
        }

        vector<int> result;
        for(int num : num2)
        {
            if(freq[num] > 0)
            {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
        // O(m + n)
    }
};