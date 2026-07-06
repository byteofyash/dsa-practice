// Last updated: 7/7/2026, 2:39:08 AM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int l = 0, r = 0;
        int max_win = 1;

        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[r];
            while ((long long)nums[r] * (r - l + 1) - sum > k) {
                sum = sum - nums[l];
                l++;
            }
            max_win = max(max_win, r - l + 1);
            r++;
        }

        return max_win;
    }
};