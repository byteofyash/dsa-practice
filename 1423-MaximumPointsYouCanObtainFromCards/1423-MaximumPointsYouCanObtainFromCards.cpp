// Last updated: 9/4/2026, 4:55:39 PM
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int l = 0;
        int winSize = n - k;
        int r = winSize;
        int windowSum = accumulate(nums.begin(), nums.begin() + r, 0);
        int minSum = windowSum;
        while (r < n) {
            windowSum -= nums[l];
            l++;
            windowSum += nums[r];
            r++;
            minSum = min(minSum, windowSum);
        }
        return totalSum - minSum;
    }
};