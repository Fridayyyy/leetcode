//
// Created by 常贵杰 on 2022/8/28.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool helper(TreeNode* a,TreeNode* b){
        if(!b){
            return true;
        }
        if(!a||a->val!=b->val){
            return false;
        }

        return helper(a->left,b->left)&&helper(a->right,b->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B)
            return false;
        if(A->val==B->val){
            if(helper(A,B))
                return true;
        }
        return isSubStructure(A->left,B)|| isSubStructure(A->right,B);
    }
};
