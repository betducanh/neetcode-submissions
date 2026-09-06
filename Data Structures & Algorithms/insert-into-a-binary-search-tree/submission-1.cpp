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
private:
    bool check = false;
    
    void traversal(TreeNode* root, int val) {
        if (!root || check) return;

        if (val > root->val) {
            if (root->right) traversal(root->right, val);
            else {
                TreeNode* newNode = new TreeNode(val);
                root->right = newNode;
                check = true;
            }
        } else {
            if (root->left) traversal(root->left, val);
            else {
                TreeNode* newNode = new TreeNode(val);
                root->left = newNode;
                check = true;
            }
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        traversal(root, val);
        if (!root) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        return root;
    }
};