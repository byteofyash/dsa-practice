// Last updated: 7/7/2026, 2:39:50 AM
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
class Solution {
public:
        int max_diameter = 0 ; 

    int diameterOfBinaryTree(TreeNode* root) {

        calcDepth(root);
        return max_diameter;

        
    }

    int calcDepth(TreeNode* root){
        if(root==NULL) return 0;

        // use post order traversal
        // go left leaf node
        int left_depth = calcDepth(root->left);

        // go to right leaf node
        int right_depth= calcDepth(root->right);

        //calculate max_depth 
        max_diameter= max(max_diameter, left_depth+right_depth);

        return 1 + max(left_depth,right_depth); // +1 to account for the parent node

    }
};