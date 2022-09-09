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
    int ans;
    int depth(TreeNode* root){
        if(!root)
            return 0;
        int L=depth(root->left);
        int R=depth(root->right);
        ans=max(ans,L+R+1);
        return max(L,R)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans=1;
        depth(root);
        return ans-1;
    }
};
