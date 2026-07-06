// Last updated: 7/7/2026, 2:42:51 AM
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int subsize = 1<<n;

        for(int i =0 ; i<subsize;i++){
            vector<int> list = {};
            for(int k =0;k<n;k++){
                if((i&(1<<k))>0) list.push_back(nums[k]);
            }
            result.push_back(list);
        }

        return result;

        
    }
};