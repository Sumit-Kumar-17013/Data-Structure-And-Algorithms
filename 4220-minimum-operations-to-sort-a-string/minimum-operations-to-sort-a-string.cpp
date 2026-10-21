class Solution {
public:
    int minOperations(string s) {
        // tc : O(n)
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // 1 operation: first char is already the min, or last char is already the max
        if (s[0] == mn || s[n - 1] == mx) return 1;

        // 2 operations: min exists in [0..n-2] or max exists in [1..n-1]
        for (int i = 0; i < n - 1; i++)
            if (s[i] == mn) return 2;
        for (int i = 1; i < n; i++)
            if (s[i] == mx) return 2;

        // min only at the last position and max only at the first position
        return 3;
    }
};