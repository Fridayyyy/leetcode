//
// Created by 常贵杰 on 2022/8/27.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void helper(TreeNode* root){
        if(!root)
            return;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        helper(root->left);
        helper(root->right);
    }
    TreeNode* mirrorTree(TreeNode* root) {
        helper(root);
    }
};
