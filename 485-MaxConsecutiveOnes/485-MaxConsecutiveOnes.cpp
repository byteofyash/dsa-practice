// Last updated: 7/7/2026, 2:39:56 AM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                currCount++;
            } else {
                maxCount = max(maxCount, currCount);
                currCount = 0;
            }
        }
        maxCount = max(maxCount, currCount);

        return maxCount;
    }
};