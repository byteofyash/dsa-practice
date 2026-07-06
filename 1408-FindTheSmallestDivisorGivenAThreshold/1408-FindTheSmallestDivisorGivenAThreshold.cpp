// Last updated: 7/7/2026, 2:39:18 AM
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        //sort(nums.begin(), nums.end());
        int low =1;

        //int high = nums[nums.size()-1];
        int high = *max_element(nums.begin(), nums.end());
        int smallDiv;
        while(low<=high){
            int mid = low + (high-low)/2;
            int sum = 0 ; 
            for(auto& x : nums){
                sum+= (x+mid-1)/mid;
            }

            if(sum <= threshold){
                smallDiv = mid;
                high = mid - 1;
            }
            else low = mid+1;

        }

        return smallDiv;
        
    }
};