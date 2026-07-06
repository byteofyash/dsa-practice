// Last updated: 7/7/2026, 2:42:56 AM
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        // first scan the first row and first col
        bool firstRowZero = false;
        bool firstColZero = false;

        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0)
                firstColZero = true;
        }

        for (int j = 0; j < col; j++) {
            if (matrix[0][j] == 0)
                firstRowZero = true;
        }

        // now scan the inner matrix
        //  put sticky notes on the first row and first col accordingly

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // wipe the inner matrix
        // based on the inner matrix

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // now wipe the firstRow and firstCol
        //  based on their fate

        if (firstRowZero) {
            // travelling along columns
            for (int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }

        if (firstColZero) {
            // travelling along rows

            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};