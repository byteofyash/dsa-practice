// Last updated: 9/4/2026, 4:53:14 PM
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