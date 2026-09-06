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
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val);
    }

    int countGoodNodes(TreeNode* root, int maxValue) {
        if (root == nullptr) return 0;

        if (root->val >= maxValue) {
            return 1 + countGoodNodes(root->left, root->val) + countGoodNodes(root->right, root->val);
        } else {
            return countGoodNodes(root->left, maxValue) + countGoodNodes(root->right, maxValue);
        }
    }
};
