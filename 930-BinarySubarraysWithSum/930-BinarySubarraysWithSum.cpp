// Last updated: 9/4/2026, 4:58:27 PM
class Solution {
int n,k;
int atMost(int goal, vector<int>&nums){
    if(goal<0) return 0;
        int l  = 0 , r = 0 ;
        int curr_sum = 0 , count = 0 ;

        while(r<n){
            curr_sum += nums[r];

           

            while(curr_sum > goal){
                curr_sum -= nums[l];
                l++;
            }

             
            count += (r-l + 1);

            r++;
        }
        
        return count;
}
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        n= nums.size();
        k = goal;
        return atMost(k, nums) - atMost(k-1,nums);
        
    }
};