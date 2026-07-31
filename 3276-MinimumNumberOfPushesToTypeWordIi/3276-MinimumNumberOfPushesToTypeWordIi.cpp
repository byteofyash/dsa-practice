// Last updated: 7/31/2026, 11:16:53 PM
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word) {
            freq[c - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int pushes = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;

            
            int cost = (i / 8) + 1;

            pushes += freq[i] * cost;
        }

        return pushes;
    }
};