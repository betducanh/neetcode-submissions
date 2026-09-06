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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr)    return true;
        
        long long cur = root->val;
        long long left = LONG_MIN;
        long long right = LONG_MAX;
        if (root->left)     left = root->left->val;
        if (root->right)    right = root->right->val;
        
        bool valid = (left < cur && cur < right) && (minVal < cur && cur < maxVal);

        return valid && dfs(root->left, minVal, root->val) && dfs(root->right, root->val, maxVal);
    }
};
