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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);

        vector<int> leftInorder;
        vector<int> rightInorder;

        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root->val) {
                leftInorder.assign(inorder.begin(), inorder.begin()+i);
                rightInorder.assign(inorder.begin()+i+1, inorder.end());
                break;
            }
        }

        vector<int> leftPreorder(preorder.begin()+1, preorder.begin()+leftInorder.size()+1);
        vector<int> rightPreorder(preorder.begin()+leftPreorder.size()+1, preorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};
