// Last updated: 7/7/2026, 2:43:32 AM
class Solution {
public:
    int reverse(int x) {

        // 2 constraints:
        // 1. rev>INT_MAX/10
        // 2.  rev == INT_MAX/10 && pop = 7
        int rev = 0;
        while(x !=0){
            int pop = x%10;
            x = x/10;


            //overflow check for positive numbers
            if(rev > INT_MAX/10|| (rev == INT_MAX/10 && pop >7)){
                return 0;
            }

            //overflow check for negative numbers
            if(rev < INT_MIN/10|| (rev == INT_MIN/10 && pop <-8)){
                return 0;
            }

            rev = rev*10 + pop;

        }

        return rev;
        
        
    }
};