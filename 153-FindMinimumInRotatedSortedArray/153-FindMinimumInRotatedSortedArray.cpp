// Last updated: 7/7/2026, 2:41:46 AM
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0 , r = n -1;

        while( l < r){
            int mid = l + (r-l)/2;

            if(nums[mid]> nums[r]){
                //search right half
                // ie push left boundary
                l = mid + 1;
            }

            if(nums[mid]<=nums[r]){
                //you may be at min
                // so just store it in case
                // search left half
                r = mid;
            }

        }

        return nums[l];
        
    }
};