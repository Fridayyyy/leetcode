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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val<p->val&&root->val<q->val){
            lowestCommonAncestor(root->right,p,q);
        }
        if(root->val>p->val&&root->val>q->val)
            lowestCommonAncestor(root->left,p,q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        TreeNode* ancestor = root;
        while (true){
            if(p->val < ancestor->val && q->val < ancestor->val){
                ancestor=ancestor->left;
            }else if(p->val > ancestor->val && q->val > ancestor->val){
                ancestor=ancestor->right;
            }else{
                break;
            }
        }
        return ancestor;
    }
};
