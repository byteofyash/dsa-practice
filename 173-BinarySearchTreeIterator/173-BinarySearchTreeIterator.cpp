// Last updated: 8/25/2026, 9:14:56 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
stack<TreeNode*> st;

void pushAllLeft(TreeNode* root){
    if(root==nullptr) return;
    while(root!=nullptr){
        st.push(root);
        root = root->left;
    }
}
public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root); 
    }
    
    int next() {
        TreeNode* curr = st.top();
        st.pop();

        // if curr has right child
        if(curr->right) pushAllLeft(curr->right);
        return curr->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */