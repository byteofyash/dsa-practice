// Last updated: 7/7/2026, 2:42:55 AM
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low =  0, mid = 0 , high = nums.size()-1;

        while(mid<=high){

            if(nums[mid]==0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }

            else if (nums[mid]==1){
                mid++;
            }

            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }
};