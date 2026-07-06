// Last updated: 7/7/2026, 2:42:31 AM
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            // no. of nodes in the current level
            int level_size = q.size();
            vector<int> current_level;

            for (int i = 0; i < level_size; i++) {
                auto curr = q.front();
                q.pop();

                current_level.push_back(curr->val);

                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
            result.push_back(current_level);

        }

        return result;
    }
};