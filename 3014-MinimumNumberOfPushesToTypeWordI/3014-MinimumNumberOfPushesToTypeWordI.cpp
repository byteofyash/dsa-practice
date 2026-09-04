// Last updated: 9/4/2026, 4:52:24 PM
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