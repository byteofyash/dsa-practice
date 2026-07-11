// Last updated: 7/11/2026, 6:40:20 PM
class Solution {
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = 0;
        unordered_map<int, int> freq;
        int ans = 0;
        while (r < n) {
            freq[nums[r]]++;
            while (freq.size() > k) {
                freq[nums[l]]--;

                if (freq[nums[l]] == 0)
                    freq.erase(nums[l]);
                l++;
            }
            ans += r - l + 1;
            r++;
        }
        return ans;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};