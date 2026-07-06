// Last updated: 7/7/2026, 2:43:15 AM
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIdx  = 1;
        for(int i =1 ; i< nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[insertIdx] = nums[i];
                insertIdx++;
            }
        }

        return insertIdx;
    }
};