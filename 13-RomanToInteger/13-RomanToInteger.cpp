// Last updated: 7/7/2026, 2:43:28 AM
class Solution {
public:
    int romanToInt(string s) {

        int n = s.size();
        unordered_map<char, int> ump = {{'I', 1},   {'V', 5},   {'X', 10},
                                        {'L', 50},  {'C', 100}, {'D', 500},
                                        {'M', 1000}};

        int ans = 0;
        for (int i = 0; i < n ; i++) {
            int curr = ump[s[i]];
            int next = ump[s[i + 1]];
            if (curr < next) {
                ans -=curr;
            } else {
                ans += curr;
            }
        }
        return ans;
    }
};