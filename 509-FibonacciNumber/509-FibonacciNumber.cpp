// Last updated: 9/4/2026, 4:58:20 PM
class Solution {

    

public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return fib(n-1) + fib(n-2);
        
    }
};