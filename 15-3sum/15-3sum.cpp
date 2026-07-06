// Last updated: 7/7/2026, 2:43:24 AM
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // sort to avoid duplicates
        sort(nums.begin(), nums.end());

        // vector to store results
        vector<vector<int>> results;

        for(int i = 0  ; i < n ; i++){
            if(i> 0 && nums[i]== nums[i-1]) continue;
            int target = - nums[i];
            int l = i+1;
            int r = n-1;
            int currsum = 0 ;
            //vector to store triplets
            vector<int> triplets;
            while(l<r){
                currsum = nums[l] + nums[r];
                // 3 cases
                // sum = target
                if(currsum == target){
                    results.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                    // while loop to skip inner duplicates
                    while(l<r && nums[l]==nums[l-1]) l++;
                    while( l< r &&nums[r]==nums[r+1] ) r--;
                    
                }
                else if ( currsum < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return results;
        
    }
};