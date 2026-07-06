// Last updated: 7/7/2026, 2:40:23 AM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int insertIdx = 0;
        for(int i = 0 ; i < n ; i ++){
            if(nums[i]!=0){
                swap(nums[insertIdx],nums[i]);
                insertIdx++;
            }
        }
        
    }
};