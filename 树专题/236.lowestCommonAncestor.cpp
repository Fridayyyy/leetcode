//
// Created by 常贵杰 on 2022/8/27.
//
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root){
            return false;
        }
        bool lson= dfs(root->left,p,q);
        bool rson= dfs(root->right,p,q);
        if(){

        }
        return lson||rson||(root->val==p->val||root->val==q->val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root||root==p||root==q)
            return root;
        TreeNode* left= lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(!left) return right;
        if (!right) return left;
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return root;
        if (root==p||root==q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(!left)
            return right;
        if(!right)
            return left;
        if(left&&right)
            return root;
        return nullptr;
    }

};
class solution{
public:
    unordered_map<int,TreeNode*> fa;
    unordered_map<int,bool> vis;
    void dfs(TreeNode* root){
        if (root->left){

        }
        if (root->right){

        }
    }
};
