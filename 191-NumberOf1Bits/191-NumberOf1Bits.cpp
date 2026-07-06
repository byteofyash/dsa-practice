// Last updated: 7/7/2026, 2:41:30 AM
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        string b = toBinary(n);
        for (auto c : b) {
            if (c == '1')
                count++;
        }
        return count;
    }

    string toBinary(int n) {
        string b = "";
        while (n > 0) {
            b += (n & 1) ? '1' : '0';
            n >>= 1;
        }
        reverse(b.begin(), b.end());
        return b;
    }
};