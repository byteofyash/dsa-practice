// Last updated: 7/19/2026, 10:14:52 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int sq = n*n;
        int maxSum = (sq* (sq+1))/2;
        unordered_map<int,int> freq;
        for(int i = 0 ; i < n ; i++ ){
            for(int j  = 0 ; j<n;j++){
                freq[grid[i][j]]++;
            }
        }
        int missing, repeated;
        for(int i = 1 ; i <= sq;i++){
            if(freq[i]==0) missing = i;
            if(freq[i]==2) repeated = i;
        }
        return {repeated, missing};
    }
};