// Last updated: 8/25/2026, 9:12:09 PM
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
int maxSum;
vector<int> postorderDFS(TreeNode* root){
    if(!root){
        return {INT_MAX, INT_MIN, 0};
    }

    auto left = postorderDFS(root->left);
    auto right = postorderDFS(root->right);


    // bst check
    if(left[1] < root->val && root->val < right[0]){
        // update sum
        int currsum = left[2] + right[2] + root->val;
        maxSum = max(currsum, maxSum);

        return {
            min(root->val, left[0]),
            max(root->val, right[1]),
            currsum
        };
    }
    
    // return poison pill if invalid
    return { INT_MIN, INT_MAX, 0};


}
public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0 ;
        postorderDFS(root);
        return maxSum;
    }
};