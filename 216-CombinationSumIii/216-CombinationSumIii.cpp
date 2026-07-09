// Last updated: 7/9/2026, 2:07:30 PM
class Solution {
    void generateAll(int i, int count, int& sum, vector<int>& curr,
                     vector<vector<int>>& result, int k, int n,
                     vector<int>& nums) {
        if (count == k) {
            if (sum == n) {
                result.push_back(curr);
                return;
            }
            if (sum > n)
                return;
        }
        if (i == nums.size())
            return;

        curr.push_back(nums[i]);
        sum += nums[i];
        count++;
        generateAll(i + 1, count, sum, curr, result, k, n, nums);

        sum -= nums[i];
        count--;
        curr.pop_back();

        generateAll(i + 1, count, sum, curr, result, k, n, nums);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        int sum = 0;
        generateAll(0, 0, sum, curr, result, k, n, nums);
        return result;
    }
};