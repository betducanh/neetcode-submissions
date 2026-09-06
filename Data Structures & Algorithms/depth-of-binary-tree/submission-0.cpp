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
    int depth = 0;
    void findMaxDepth(TreeNode* node, int curDepth) {
        if (!node) {
            depth = max(depth, curDepth);
            return;
        }

        findMaxDepth(node->left, curDepth+1);
        findMaxDepth(node->right, curDepth+1);
    }
public:

    int maxDepth(TreeNode* root) {
        findMaxDepth(root, 0);
        return depth;
    }
};
