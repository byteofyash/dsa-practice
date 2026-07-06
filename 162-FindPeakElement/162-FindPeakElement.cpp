// Last updated: 7/7/2026, 2:41:42 AM
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0 ; 
        int r = nums.size()-1;

        while(l<r){
            int mid = l + (r-l)/2;

            if(nums[mid]>nums[mid+1]){
                // goign right will goign downhill
                // so go left
                r = mid; // you might be exactly at the peak or another peak maybe to the left
            }
            else{
                // you are ascending
                // peak is to the right, so go right
                l = mid+ 1;
            }
        }

        // when l==r , loops break and you have found you peak
        return r;
        
    }
};