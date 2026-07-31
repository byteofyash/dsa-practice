// Last updated: 7/31/2026, 11:16:55 PM
class Solution {
public:
    int minimumPushes(string word) {
        int pushes = 0;

        for (int i = 0; i < word.size(); i++) {
            pushes += (i / 8) + 1;
        }

        return pushes;
    }
};