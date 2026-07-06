// Last updated: 7/7/2026, 2:42:08 AM
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int state = 0 ;

        for(auto& x : nums){
            state = state ^ x;
        }

        return state;
    }
};