// Last updated: 7/7/2026, 2:43:30 AM
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        bool neg = false;
        long long temp = 0;
        while (i < n && s[i] == ' ')
            i++;

        if (i == n)
            return 0;

        if (s[i] == '-' || s[i] == '+') {
            neg = (s[i] == '-');
            i++;
        }

        if (i == n)
            return 0;
        int limitDigit;

        if (!isdigit(s[i]))
            return 0;

        else {
            int limit = neg ? 8 : 7;
            while (i < n && isdigit(s[i])) {
                int digit = s[i] - '0';
                if (temp > INT_MAX / 10 ||
                    (temp == INT_MAX / 10 && digit > limit)) {
                    return neg ? INT_MIN : INT_MAX;
                }
                temp = temp * 10 + digit;
                i++;
            }
        }
        return neg ? -temp : temp;
    }
};