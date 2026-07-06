// Last updated: 7/7/2026, 2:43:22 AM
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < n-3; i++) // should leave room for 3 pointers
        {
            //check for duplicates
            if(i> 0 && nums[i]==nums[i-1]) continue;
            for(int j = i+1 ; j<n-2;j++)
            // should leave for 2 pointers
            {
                if(j> i+1 && nums[j]==nums[j-1]) continue;


                int l = j+1;
                int r = n-1;

                while(l< r){
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];

                    if(sum == target){
                        results.push_back({nums[i] , nums[j] , nums[l] , nums[r]});
                        l++;
                        r--;

                        while(l<r && nums[l]==nums[l-1]) l++;
                        while (l<r && nums[r]==nums[r+1])r--;

                    }

                    else if ( sum < target) l++;
                    else r--;
                }

            }
        }
        return results;
        
    }
};