// Last updated: 7/7/2026, 2:43:06 AM
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();


// taking transpose of a matrix
        for (int i = 0; i < row; i++) {
            for (int j = i; j < col; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
// reversing each row
for(int i = 0 ; i < row;i++){
    reverse(matrix[i].begin(), matrix[i].end());
}




    }
};