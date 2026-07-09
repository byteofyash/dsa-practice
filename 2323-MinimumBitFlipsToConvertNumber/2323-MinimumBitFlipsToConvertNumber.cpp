// Last updated: 7/9/2026, 5:05:53 PM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0 ;
        int a = start ^ goal;
        while(a>0){
            a = a & a-1;
            count++;
        }
        return count;
    }
};