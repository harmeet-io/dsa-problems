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
    bool isBal;
    int rec(TreeNode* root) {
        if(root==NULL) return 0;

        int left = rec(root->left);
        int right = rec(root->right);

        if(abs(left-right) > 1) isBal = false;

        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode* root) {
        isBal = true;

        rec(root);

        return isBal;
    }
};
