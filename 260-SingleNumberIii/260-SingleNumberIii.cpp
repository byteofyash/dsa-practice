// Last updated: 7/9/2026, 6:05:32 PM
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long result_xor = 0;
        for (auto& x : nums) {
            result_xor ^= x; // result =  x^y
        }

        long long mask = (result_xor) & (-result_xor); // isolate the righmost set bit

        int state1 = 0;
        int state2 = 0;
        for(auto& x : nums){
           if( (x & mask) == 0 ){
                state1 = state1 ^x;
           }
           else {
                state2 = state2 ^x;
           }
            
        }

        return {state1, state2};
    }
};