// Last updated: 8/25/2026, 9:15:27 PM
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        int n = beginWord.size();
        unordered_set<string> st;
        for (auto& word : wordList) {
            st.insert(word);
        }

        if (st.find(endWord) == st.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string currword = q.front();
                q.pop();

                if(currword==endWord) return dist + 1;

                for (int i = 0; i < n; i++) {
                    char orgChar = currword[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orgChar)
                            continue;
                        currword[i] = c;
                        if (st.find(currword) != st.end()) {
                            q.push(currword);
                            st.erase(currword);
                        }
                        currword[i] = orgChar;
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};
