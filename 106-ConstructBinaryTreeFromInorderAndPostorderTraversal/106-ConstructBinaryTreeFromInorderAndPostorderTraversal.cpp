// Last updated: 8/25/2026, 9:15:42 PM
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
    TreeNode* build(vector<int>& postorder, int postStart, int postEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& inMap) {
        //base case
        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        // getting rootVal and creating a new node
        int rootVal =postorder[postEnd] ;
        TreeNode* root = new TreeNode(rootVal);

        // getting rootIndex
        int inRoot = inMap[rootVal];

        // calculating numsleft to separate left and right subtree in postorder
        int numsLeft = inRoot - inStart;

        // building left subtree
        root->left = build(postorder, postStart, postStart + numsLeft-1,
                           inorder, inStart, inRoot - 1, inMap);

        // building right subtree
        root->right =
            build(postorder, postStart + numsLeft , postEnd-1,
                  inorder, inRoot + 1, inEnd, inMap);

                return root;


    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // building unodred inMap
        unordered_map<int, int> inMap;
        int i = 0;
        for (auto node : inorder) {
            inMap[node] = i;
            i++;
        }

        return build(postorder, 0, postorder.size() - 1, inorder, 0,
                     inorder.size() - 1, inMap);
    }
};