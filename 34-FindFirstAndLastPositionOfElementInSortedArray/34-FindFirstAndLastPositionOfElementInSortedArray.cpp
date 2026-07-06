// Last updated: 7/7/2026, 2:43:09 AM
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;

        int firstpos = -1, lastpos = -1;

        // bs1: for first occurence if target is present
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (target == nums[mid]) {
                // save mid as first_pos
                firstpos = mid;

                // push right boundary, ie, search in left half
                r = mid - 1;
            }

            else if (target > nums[mid]) {
                l = mid + 1;
            }

            else
                r = mid - 1;
        }

        // resetting l and r for next search
        l = 0, r = n - 1;

        // bs2: for last occurence if target is present
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (target == nums[mid]) {
                // save mid as first_pos
                lastpos = mid;

                // push left boundary, ie, search in right half
                l = mid + 1;
            }

            else if (target > nums[mid]) {
                l = mid + 1;
            }

            else
                r = mid - 1;
        }

        return {firstpos, lastpos};
    }
};