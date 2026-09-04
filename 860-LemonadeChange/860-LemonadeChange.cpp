// Last updated: 9/4/2026, 4:58:59 PM
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        // let's initialize five and ten to count 5 and 10 dollar bills
        int five = 0;
        int ten = 0;

        for (auto& bill : bills) {
            if (bill == 5)
                five++;

            else if (bill == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } 
                else
                    return false;
            } 
            
            else { // bil of $20

                // first choice will be to sacrifice 10 dollar bill ,
                // cause its less flexible
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }

                // if we dont have ten dollar bills
                // then we have to sacrifice out highly versatile 5 usd bills

                else if (five >= 3) {
                    five -= 3;
                } 
                
                else
                    return false;
            }
        }

        return true;
    }
};