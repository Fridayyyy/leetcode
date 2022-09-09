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
    int val=0;
    void helper(TreeNode* root,int& k){
        if(!root)
            return nullptr;
        helper(root->right,k);
        k--;
        if(!k) val=root->val;
        helper(root->left,k);
    }
    int kthLargest(TreeNode* root, int k) {
        helper(root,k);
        return val;
    }
};
