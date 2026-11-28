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
    int path;
    int rec(TreeNode* root){
        if(root==NULL) return 0;

        int left = rec(root->left);
        int right = rec(root->right);

        path = max(path, left + right);

        return 1 + max(left, right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        path = 0;
        rec(root);
        return path;
    }
};
