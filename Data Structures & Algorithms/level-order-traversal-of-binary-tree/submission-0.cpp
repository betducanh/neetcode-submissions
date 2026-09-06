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
    vector<vector<int>> result;
    int levelCount = 0;
public:
    void traversal(TreeNode* root, int level) {
        if (root == nullptr) return;

        if (level > levelCount) {
            result.push_back({});
            levelCount++;
        }

        result[level-1].push_back(root->val);
        traversal(root->left, level + 1);
        traversal(root->right, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        traversal(root, 1);
        return result;
    }
};
