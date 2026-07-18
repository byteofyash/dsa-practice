// Last updated: 7/18/2026, 8:28:52 PM
class Solution {

public:
    int countPalindromes(string s) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        long long leftCnt[10] = {};
        long long rightCnt[10] = {0};

        long long leftPair[10][10] = {};
        long long rightPair[10][10] = {};

        for (int i = s.size() - 1; i >= 0; i--) {
            int d = s[i] - '0';
            for (int x = 0; x < 10; x++)
                rightPair[d][x] += rightCnt[x];
            rightCnt[d]++;
        }

        

        

        for (int i = 0; i < s.size(); i++) {
            int d = s[i] - '0';

            rightCnt[d]--;

            for (int x = 0; x < 10; x++)
                rightPair[d][x] -= rightCnt[x];

            

            for (int x = 0; x < 10; x++)
                for (int y = 0; y < 10; y++)
                    ans = (ans + leftPair[x][y] * rightPair[y][x]) % MOD;

            for (int x = 0; x < 10; x++)
                leftPair[x][d] += leftCnt[x];

            leftCnt[d]++;
        }

        return ans;
    }
};