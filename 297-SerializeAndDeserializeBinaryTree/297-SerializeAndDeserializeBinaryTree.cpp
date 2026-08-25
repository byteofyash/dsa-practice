// Last updated: 8/25/2026, 9:14:13 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
string serHelper(TreeNode* root, string& s){
    if(root == nullptr){
        s += "#,";
        return s;
    }
    s+= to_string(root->val) + ",";
    serHelper(root->left, s);
    serHelper(root->right, s);
    return s;
}

TreeNode* deserHelper(stringstream& ss){
    string token;
    if(!getline(ss, token, ',')) return nullptr;
    if(token=="#") return nullptr;

    // create TreeNode
    TreeNode* root = new TreeNode(stoi(token));
    root->left = deserHelper(ss);
    root->right = deserHelper(ss);
    return root;
}
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";
        string s = "";
        return serHelper(root, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return nullptr;

        //create a stringstream from the data string
        stringstream ss(data);
        return deserHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));