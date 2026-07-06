// Last updated: 7/7/2026, 2:41:01 AM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        
        bool freqgreaterthan1 = false;
        sort(nums.begin(),nums.end());

        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) freqgreaterthan1 = true;
        }
        

        if(freqgreaterthan1) return true;
        else return false;
        
    }
};