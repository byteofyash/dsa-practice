// Last updated: 7/13/2026, 11:31:47 PM
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
int ans = INT_MIN;
int dfs(TreeNode* root){
    //base case
    if(root==nullptr) return 0;

    int left  = dfs(root->left);
    int right  = dfs(root->right);

    left = max(0,left); // cause left can be -ve and -ve doesnt contribute to max sum
    right = max(0,right);

    ans = max(ans, left + right + root->val); // update global ans but dont return it

    return root->val + max(left,right); // return best path to parent
}
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};