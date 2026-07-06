// Last updated: 7/7/2026, 2:39:20 AM
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        // lets start by defining rows and columns

        int r = matrix.size();
        int c = matrix[0].size();
        int total_squares = 0;
        // to count the number of sq submatrixes ending
        // at a particular index i

        // now lets iterate row and column wise

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] =
                        1 + min({matrix[i - 1][j], matrix[i - 1][j - 1],
                                 matrix[i][j - 1]});
                }

                total_squares += matrix[i][j];
            }
        }

        return total_squares;
    }
};