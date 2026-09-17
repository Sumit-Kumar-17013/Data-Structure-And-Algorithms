class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int n = matrix.size();
        int m = matrix[0].size();

        int i = 0;
        int j = -1;
        int dir = 1;

        while (n > 0 && m > 0) {


            for (int k = 0; k < m; k++) {
                j += dir;
                res.push_back(matrix[i][j]);
            }
            n--;

            for (int k = 0; k < n; k++) {
                i += dir;
                res.push_back(matrix[i][j]);
            }
            m--;

            dir *= -1;
        }

        return res;
    }
};