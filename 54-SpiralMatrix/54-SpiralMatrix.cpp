// Last updated: 7/7/2026, 2:43:01 AM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //define the 4 directions
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0 ;
        int right = matrix[0].size()-1;

        vector<int> ans;

        while(top<=bottom && left<=right){
            //walk the top wall, left to right
            for(int i = left; i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;


            //walk the right wall, top to bottom
             for(int i = top; i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            //walk the bottom wall, left to right
            // check whether top and bottom have not crossed( for non sq matrices)
            if(top<=bottom){
                 for(int i = right; i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            }


            if(left<=right){
            //walk the left wall,bottom to top
             for(int i = bottom; i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            }

        }
        return ans;
        
    }
};