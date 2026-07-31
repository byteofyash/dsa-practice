// Last updated: 7/31/2026, 11:23:17 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m  =matrix.size();
        int n = matrix[0].size();

        int low = 0, high = m*n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int row = mid/n, col = mid%n;

            int val = matrix[row][col];

            if(val==target) return true;
            else if(val>target) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
};