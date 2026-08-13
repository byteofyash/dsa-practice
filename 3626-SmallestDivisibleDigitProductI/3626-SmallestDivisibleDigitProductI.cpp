// Last updated: 8/13/2026, 9:30:13 PM
class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int x = n;
            int product = 1;

            while (x > 0) {
                product *= (x % 10);
                x /= 10;
            }

            if (product % t == 0)
                return n;

            n++;
        }
    }
};