// Last updated: 9/19/2026, 1:53:23 PM
struct TrieNode{
    TrieNode* children[2];
    bool isEnd;

    TrieNode(){
        for(int i  = 0 ; i< 2; i++) children[i] = nullptr;
        isEnd = false;
    }
};

class Trie{
public: 
TrieNode* root;

Trie(){
    root = new TrieNode();
}
void insert(int n){
    TrieNode* curr = root;
    for(int i= 30; i>=0;i--){
        int bit =( n >>i )& 1;
        if(curr->children[bit]==nullptr){
            curr->children[bit] = new TrieNode(); 
        }
        curr = curr->children[bit];
    }
     curr->isEnd = true;
}

int getMaxXOR(int n ){
    TrieNode* curr = root;
    int maxXor = 0;
    for(int i= 30; i>=0;i--){
        int bit =( n >>i )& 1;
        int toggledBit = 1 - bit;
        if(curr->children[toggledBit]!=nullptr){
            maxXor |= 1<<i; 
            curr = curr->children[toggledBit];
        }
        else curr = curr->children[bit];
    }
    return maxXor;
}

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie obj;
        for(auto& x : nums) obj.insert(x);

        int res = 0;
        for(auto& x : nums){
            res = max(res, obj.getMaxXOR(x));
        }

        return res;
    }
};