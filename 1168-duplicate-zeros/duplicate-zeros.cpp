class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();

        vector<int> dest(n);

        int s = 0, d = 0;

        while (s < n && d < n) {
            if (arr[s] == 0) {
                dest[d] = 0;
                d++;

                if (d < n) {
                    dest[d] = 0;
                    d++;
                }
            }
            else {
                dest[d] = arr[s];
                d++;
            }

            s++;
        }
        for (int i = 0; i < n; i++) {
            arr[i] = dest[i];
        }
    }
};