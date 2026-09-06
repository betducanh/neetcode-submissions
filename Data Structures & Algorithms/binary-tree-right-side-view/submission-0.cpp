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
    vector<int> result;
public:
    void traversal(TreeNode* root, int level) {
        if (root == nullptr) return;
        
        if (level > result.size()) {
            result.push_back(root->val);
        }

        traversal(root->right, level+1);
        traversal(root->left, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        traversal(root, 1);
        return result;
    }
};
