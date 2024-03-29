//
// Created by 常贵杰 on 2022/8/27.
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
    int val=0;
    void postOrder(TreeNode* root){
        if(!root)
            return;
        postOrder(root->right);
        root->val+=val;
        val=root->val;
        postOrder(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        postOrder(root);
        return root;
    }
};