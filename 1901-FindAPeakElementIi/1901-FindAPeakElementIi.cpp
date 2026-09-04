// Last updated: 9/4/2026, 4:54:17 PM
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0 ;
        int high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int peak = 1;
            int row = 0;
            for(int i = 0 ; i<m;i++){
               if(mat[i][mid]>mat[row][mid]) row = i;
            }
            int left = (mid==0)?-1 : mat[row][mid-1];
            int right = (mid==n-1)? -1: mat[row][mid+1];

            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }

            if(right > mat[row][mid]) low = mid+1;
            else high = mid -1;
        }

        return {};
        
    }
};