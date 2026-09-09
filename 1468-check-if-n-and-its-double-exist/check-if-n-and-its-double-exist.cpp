class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> seen;
        // tc = O(n)

        for(int num : arr)
        {
            if(seen.count(2 * num))
            {
                return true;
            }
            if(num % 2 == 0 && seen.count( num / 2))
            {
                return true;
            }

            seen.insert(num);
        }
        return false;
    }
};