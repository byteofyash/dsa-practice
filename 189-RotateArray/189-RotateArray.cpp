// Last updated: 7/7/2026, 2:41:34 AM
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
         k = k %n;

         //rev entire arr
         reverse(nums.begin(), nums.end());
         // reverse(first, last];

         //rev first k
         reverse(nums.begin(), nums.begin()+k);

         // rev last last k
         reverse(nums.begin()+k, nums.end());

        
    }
};