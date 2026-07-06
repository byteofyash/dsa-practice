// Last updated: 7/7/2026, 2:39:29 AM
class Solution {

    

public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1) + fib(n-2);
        
    }
};