// Last updated: 9/4/2026, 4:56:36 PM
class Solution {
    int n;
int atMost(int k , vector<int>& nums){
    if(k<0) return 0 ;

    int l = 0 , r = 0;
    int oddCnt = 0;
    int count = 0;

    while(r<n){
        //include
        if(nums[r]%2!=0) oddCnt++;

        //check
        while(oddCnt > k){
           if( nums[l]%2!=0 )oddCnt--;
            l++;
        }

        count += r-l +1;
        r++;


    }
    return count;
}
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        n = nums.size();
        return atMost(k,nums) - atMost(k-1, nums);
    }
};