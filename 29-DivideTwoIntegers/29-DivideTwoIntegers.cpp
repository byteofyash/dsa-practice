// Last updated: 7/9/2026, 6:06:12 PM
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long dend = dividend;
        long long divi = divisor;
        bool neg = (dend < 0) ^ (divi < 0);
        dend = abs(dend);
        divi = abs(divi);
        int shift = 0;
        long long quotient = 0;

        while (dend >= divi) {
            shift = 0;
            while ((divi <<  (shift+1)) <= dend) {
                shift++;
            }
            dend  -= (divi << (shift));
            quotient += 1LL << (shift);
        }
        if (neg) {
            quotient = -quotient;
            if (quotient < INT_MIN)
                return INT_MIN;
            return quotient;

        } else {
            if (quotient > INT_MAX)
                return INT_MAX;
            return quotient;
        }
    }
};