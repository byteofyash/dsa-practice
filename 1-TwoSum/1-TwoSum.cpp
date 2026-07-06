// Last updated: 7/7/2026, 2:43:38 AM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> seen;
        for(int i = 0 ; i< n;i++){
            int complement = target - nums[i];

            if(seen.count(complement)){
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};