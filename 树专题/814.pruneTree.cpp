//
// Created by 常贵杰 on 2022/8/28.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* helper(TreeNode* root){
        if(!root)
            return nullptr;
        root->left= helper(root->left);
        root->right= helper(root->right);
        if((!root->left&&!root->right)&&root->val==0){
            return nullptr;
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) {
        helper(root);
    }
};
