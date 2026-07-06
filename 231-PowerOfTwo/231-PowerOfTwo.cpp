// Last updated: 7/7/2026, 2:40:52 AM
class Solution {
public:
    bool isPowerOfTwo(int n) {

        return (n>0) && ( (n & (n-1))==0); 
        
    }
};