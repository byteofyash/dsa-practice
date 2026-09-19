// Last updated: 9/19/2026, 1:54:02 PM
struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(){ // constructor to initialize the class
    for(int i = 0 ; i < 26;i++) children[i] = nullptr;
    isEndOfWord = false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root  = new TrieNode();  
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }
};