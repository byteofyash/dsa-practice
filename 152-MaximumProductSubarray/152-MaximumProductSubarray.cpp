// Last updated: 7/31/2026, 11:21:51 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int n = nums.size();
        long long maxEnd = nums[0], minEnd = nums[0];
        long long newMax = maxEnd, newMin = minEnd;
        long long ans = nums[0];
        for (int i = 1; i < n; i++) {
            long long x = nums[i];
            
            newMax = max({x, maxEnd * x, minEnd * x});
            newMin = min({x, maxEnd * x, minEnd * x});

            maxEnd = newMax;
            minEnd = newMin;

            ans = max(ans, maxEnd);
        }
        return ans;
    }
};