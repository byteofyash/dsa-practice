// Last updated: 7/13/2026, 11:31:53 PM
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
    void bfs(TreeNode* root, vector<vector<int>>& result) {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        q.push(root);
        bool lToR = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> currLvl;
            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                q.pop();
                currLvl.push_back(top->val);
                if (top->left != nullptr)
                    q.push(top->left);
                if (top->right != nullptr)
                    q.push(top->right);
            }
            if (lToR) {
                result.push_back(currLvl);
                lToR = !lToR;
            } else {
                reverse(currLvl.begin(), currLvl.end());
                result.push_back(currLvl);
                lToR = !lToR;
            }
        }
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, result);
        return result;
    }
};