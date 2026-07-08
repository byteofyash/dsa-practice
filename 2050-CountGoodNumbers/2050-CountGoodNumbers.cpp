// Last updated: 7/8/2026, 6:48:47 PM
class Solution {
 const long long MOD = 1e9+7;
long long pow(long long base, long long exp){
    if(exp==0) return 1;
    long long half = pow(base, exp/2);
    long long result = (half * half) % MOD;
    if(exp % 2 == 1) result = (result * base) % MOD;
    return result;
}
public:
    int countGoodNumbers(long long n) {
       int MOD = 1e9 + 7;
       long long even_choices = pow(5,(n+1)/2);
       long long odd_choices = pow(4, n/2);
       return (even_choices* odd_choices) % MOD;


    }
};