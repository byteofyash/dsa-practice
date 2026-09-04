// Last updated: 9/4/2026, 4:57:57 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0 ; int l = 0 ;
        int zeroCount = 0 ;
        int maxLen = 0;
        while(r<n){
            if (nums[r]==0){
                zeroCount++;
            }
            while(zeroCount > k ){
                if(nums[l]==0)zeroCount--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
        
    }
};