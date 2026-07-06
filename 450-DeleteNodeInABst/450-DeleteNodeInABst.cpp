// Last updated: 7/7/2026, 2:40:11 AM
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
        TreeNode* helper(TreeNode* root) {
            if (root->left == NULL)
                return root->right;
            if (root->right == NULL)
                return root->left;

            // if both left and right of root isn't null
            TreeNode* rightChild = root->right;
            TreeNode* lastRight = findLastChild(root->left);
            lastRight->right = rightChild;
            return root->left;
        }

        TreeNode* findLastChild(TreeNode* root) {
            if (root->right == NULL)
                return root;
            else
                return findLastChild(root->right);
        }

    public:
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (root == NULL)
                return NULL;

            if (root->val == key) {
            return helper(root);
            }

            TreeNode* dummy = root;


            while (root != NULL) {
                if (key < root->val) {

                    if (root->left != NULL && root->left->val == key) {
                        root->left = helper(root->left);
                       
                        break;
                    }
                    else root = root->left;

                } else {
                    if (root->right != NULL && root->right->val == key) {
                        root->right = helper(root->right);
                       
                        break;
                    }

                    else root= root->right;
                }
            }
            return dummy;
        }
    };