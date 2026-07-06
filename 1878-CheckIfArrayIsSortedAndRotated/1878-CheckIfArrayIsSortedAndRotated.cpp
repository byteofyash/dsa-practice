// Last updated: 7/7/2026, 2:39:10 AM
class Solution {
public:
    bool check(vector<int>& nums) {

        int n = nums.size();
        int drops = 0 ; 

        for(int i = 0 ; i< n ;i++){
            if(nums[i]>nums[(i+1) % n]) drops++;
        }


        return (drops <=1);
        
    }
};