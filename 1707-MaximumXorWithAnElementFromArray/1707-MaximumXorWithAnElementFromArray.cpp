// Last updated: 9/16/2026, 12:35:25 AM
#define all(v) (v).begin(), (v).end()
#define pb push_back

struct TrieNode {
    TrieNode* children[2];

    TrieNode() {
        for (int i = 0; i < 2; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }
    void insert(int n) {
        TrieNode* curr = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (curr->children[bit] == nullptr) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }

    int getMaxXOR(int n) {
        TrieNode* curr = root;
        int maxXor = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (n >> i) & 1;
            int toggledBit = 1 - bit;
            if (curr->children[toggledBit] != nullptr) {
                maxXor |= 1 << i;
                curr = curr->children[toggledBit];
            } else
                curr = curr->children[bit];
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(all(nums));

        using State = tuple<int, int, int>;
        vector<State> q;

        for (int i = 0; i < queries.size(); i++) {
            vector<int> qry = queries[i];
            q.pb({qry[1], qry[0], i});
        }

        sort(all(q));

        vector<int> ans(q.size(),-1);
        int numsIdx= 0;
        Trie obj;
        for (int i = 0; i < q.size(); i++) {
            auto [m,x,orgIdx] = q[i];
            while (numsIdx < nums.size() && nums[numsIdx]<=m) {
                obj.insert(nums[numsIdx]);
                numsIdx++;
            }
            if(numsIdx==0) ans[orgIdx] = -1;
            else ans[orgIdx] = obj.getMaxXOR(x);
        }

        return ans;
    }
};