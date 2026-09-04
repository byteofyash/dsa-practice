// Last updated: 9/4/2026, 4:58:57 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void trackParents(TreeNode*& root,
                      unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // left child
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }

            // right child
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;
        trackParents(root, parent);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;

        visited.insert(target);
        q.push(target);

        int dist = 0;

        while (!q.empty()) {
            if (dist == k)
                break;
            int size = q.size();
           

            for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();  q.pop();
                // left neighbour
                if (curr->left && visited.count(curr->left)==0) {
                    visited.insert(curr->left);
                    q.push(curr->left);
                }

                // right neighbour
                if (curr->right && visited.count(curr->right)==0) {
                    visited.insert(curr->right);
                    q.push(curr->right);
                }

                // parent
                if (parent[curr] && visited.count(parent[curr])==0) {
                    visited.insert(parent[curr]);
                    q.push(parent[curr]);
                }
            }
            dist++;
        }

        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};