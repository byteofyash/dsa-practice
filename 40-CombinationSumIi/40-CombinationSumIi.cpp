// Last updated: 7/9/2026, 11:47:11 AM
class Solution {
    void generateAll(int i, vector<int>& curr, int& sum,
                     vector<vector<int>>& result, vector<int>& candidates,
                     int target) {
       
        if (sum == target) {
            result.push_back(curr);
            return;
        }
        if (sum > target)
            return;
         if (i == candidates.size())
            return;
        
        // iterate over all candidates to avoid siblings at same level
        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) {
                continue;
            }
            // pick
            curr.push_back(candidates[j]);
            sum += candidates[j];
            // recurse
            generateAll(j + 1, curr, sum, result, candidates, target);

            // backtrack
            sum -= candidates[j];
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        generateAll(0, curr, sum, result, candidates, target);
        return result;
    }
};