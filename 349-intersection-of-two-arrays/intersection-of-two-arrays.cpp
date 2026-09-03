class Solution {
public:
    vector<int> intersection(vector<int>& num1, vector<int>& num2) {
        set<int> s1(num1.begin() , num1.end());
        set<int> result;
        
        for(int num : num2)
        {
            if(s1.count(num))
            {
                result.insert(num);
            }
        }
        return vector<int>(result.begin() , result.end());
        // O(m + n)
    }
};