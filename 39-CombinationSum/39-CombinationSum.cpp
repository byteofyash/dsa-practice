// Last updated: 7/9/2026, 11:47:13 AM
class Solution {
void generateAll(int i, vector<int>& curr, int& sum, vector<vector<int>>& result,vector<int>& candidates, int target){
    if(i==candidates.size()) return;
    if(sum> target) return;
    if(sum==target){
        result.push_back(curr);
        return;
    }
    //pick
    curr.push_back(candidates[i]);
    sum += candidates[i];
    //recurse
    generateAll(i,curr, sum, result, candidates, target);
    //backtrack
    sum -= candidates[i];
    curr.pop_back();

    
    generateAll(i+1, curr, sum, result, candidates, target);


}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        int sum = 0;
        generateAll(0,curr, sum, result, candidates, target);
        return result;
        
    }
};