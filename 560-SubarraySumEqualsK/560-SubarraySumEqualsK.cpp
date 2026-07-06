// Last updated: 7/7/2026, 2:39:46 AM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixMap;

        int n = nums.size();
        int curr_sum = 0;
        int count = 0 ; 
        prefixMap[0]=1;

        for(int i = 0 ; i < n ; i ++){
            curr_sum += nums[i];

            int target = curr_sum -k;
            if(prefixMap.find(target)!=prefixMap.end()){
                count += prefixMap[target];
            }
            prefixMap[curr_sum]++;

            
        }

        return count;
        
    }
};