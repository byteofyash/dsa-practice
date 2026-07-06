// Last updated: 7/7/2026, 2:42:48 AM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r= n-1;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(nums[mid]==target){
                return true;
            }

            // if edges match mid
            // shrink the edges inward
            if(nums[l]==nums[mid]&& nums[r]==nums[mid]){
                l++;
                r--;
                continue;
            }

            else if ( nums[l]<=nums[mid]){
                if(nums[l]<=target && target <= nums[mid]){
                    r = mid-1;
                }
                else l = mid + 1;
            }

            else{
                if(nums[mid]<=target && target <= nums[r]){
                    l = mid+1;
                }
                else r = mid - 1;

            }
        }

        return false;
    }
};