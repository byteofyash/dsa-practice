// Last updated: 8/26/2026, 1:12:20 PM
class Solution {
    unordered_map<string, int> dist;
    vector<vector<string>> ans;
    string startWord;
    void dfs(string word, vector<string>& path) {

        if (word == startWord) {
            vector<string> currpath = path;
            reverse(currpath.begin(), currpath.end());
            ans.push_back(currpath);
            return;
        }

        int currDist = dist[word];

        for (int i = 0; i < word.size(); i++) {
            char orgChar = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                if (dist.count(word) && dist[word] == currDist - 1) {
                    path.push_back(word);
                    dfs(word, path);
                    path.pop_back();
                }
            }
            word[i] = orgChar;
        }

        return;
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st;
        startWord = beginWord;
        for (auto& word : wordList) {
            st.insert(word);
        }

        if (st.find(endWord) == st.end())
            return {};
        st.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string currWord = q.front();
                q.pop();
                int currDist = dist[currWord];
                for (int i = 0; i < currWord.size(); i++) {
                    char orgChar = currWord[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == orgChar) continue;
                        currWord[i] = c;
                        if (st.find(currWord) != st.end()) {
                            q.push(currWord);
                            dist[currWord] = currDist + 1;
                            st.erase(currWord);
                        }
                    }
                    currWord[i] = orgChar;
                }
            }
        }
        if (!dist.count(endWord))
            return {};
        vector<string> path = {endWord};
        dfs(endWord, path);
        return ans;
    }
};