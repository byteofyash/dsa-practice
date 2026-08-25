// Last updated: 8/25/2026, 9:15:45 PM
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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& inMap) {
        
        // base case
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // finding root value from predoer
        int rootVal = preorder[preStart];

        //creating the root node
        TreeNode* root = new TreeNode(rootVal);

        // getting its index
        int inRoot = inMap[rootVal];

        // variables
        int numsLeft = (inRoot - 1) - inStart + 1;

        // building left subtree
        root->left = build(preorder, preStart + 1, preStart + 1 + numsLeft - 1,
                           inorder, inStart, inRoot - 1, inMap);

        // building right subtree
        root->right =
            build(preorder, preStart + numsLeft + 1, preEnd,
                  inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // building unodred inMap
        unordered_map<int, int> inMap;
        int i = 0;
        for (auto node : inorder) {
            inMap[node] = i;
            i++;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, inMap);
    }
};