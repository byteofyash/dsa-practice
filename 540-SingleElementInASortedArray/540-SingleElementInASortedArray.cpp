// Last updated: 7/7/2026, 2:39:52 AM
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0 ;
        int right = n-1;

        while(left<right){
            int mid =left+ (right-left)/2;
            if(mid%2!=0) mid = mid -1;

            if(nums[mid]==nums[mid+1]){
                left = mid + 2;
            }
            else right = mid;
        }

        return nums[right];

        
    }
};