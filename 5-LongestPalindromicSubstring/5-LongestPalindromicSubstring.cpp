// Last updated: 7/7/2026, 4:19:06 AM
class Solution {
    void Expand(int l, int r, int& bestStart, int& bestLen, int n, string& s ) {
        int currLen = 0;
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }
        currLen = (r - 1) - (l + 1) + 1;
        if (currLen > bestLen) {
            bestLen = currLen;
            bestStart = l + 1;
        }
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        int bestLen = 1, bestStart = 0;
        for (int i = 0; i < n; i++) {
            Expand(i,i,bestStart, bestLen,n,s);
            Expand(i,i+1,bestStart, bestLen,n,s);
        }
        return s.substr(bestStart,bestLen);
    }
};