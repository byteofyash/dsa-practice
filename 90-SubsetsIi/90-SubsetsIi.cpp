// Last updated: 7/9/2026, 6:05:58 PM
class Solution {
    void generateAll(int i, vector<int>& curr, vector<vector<int>>& result, vector<int>& nums) {
        result.push_back(curr);
        for(int j = i ; j< nums.size();j++){
            if(j>i && nums[j]== nums[j-1]) continue;
            curr.push_back(nums[j]);
            generateAll(j+1,curr, result, nums);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr;
        generateAll(0, curr, result, nums);
        return result;
    }
};