// Last updated: 7/7/2026, 2:43:04 AM
class Solution {

    double recursiveBinExpo(double& x,long long n ){

        if(n==0) return 1.0;

        //calc first half
        double half = recursiveBinExpo(x,n/2);

        if(n%2==0){
            return half * half;
        }
        else{
            return half * half * x;
        }
    }
public:
    double myPow(double x, int n) {

        long long nn = n; // casting to store 2^31

        //handling negative numbers
        if(nn<0){
            nn = -nn;
            x = 1.0/x;
        }

        return recursiveBinExpo(x,nn); 
    }
};