// Last updated: 7/7/2026, 2:40:27 AM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {

private:
    void getPath(TreeNode* root, string currentPath, vector<string>& result) {
        //base case
        if (root == NULL)
            return;
        
        //convert int root value to string
        string nodeValue = to_string(root->val);

        //leaf node check
        if (root->left==NULL && root->right == NULL)
            result.push_back(currentPath+nodeValue);

        
        //recursive functions to left and right subtrees; building string
        getPath(root->left, currentPath+ nodeValue+ "->", result);
        getPath(root->right, currentPath+ nodeValue+ "->", result);
        
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        getPath(root,"",result);
        return result;
    }
};