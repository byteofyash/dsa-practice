// Last updated: 7/7/2026, 2:43:08 AM
class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> nums = arr;
        int min_idx = INT_MAX;
        
        int l = 0 ; 
        int r = n -1;
        int mid = l + (r-l)/2;
        while( l <=r ){
            
            mid = l + (r-l)/2;
            int curr_idx = mid;
            
            
            if(nums[mid]>=target){
                r = mid -1;
                min_idx = min( min_idx,curr_idx);
            }
            
            else{
                l = mid +1;
            }
        }
        if(min_idx!=INT_MAX) return min_idx;
        else return n;
    }
};