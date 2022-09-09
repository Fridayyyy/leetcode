//
// Created by 常贵杰 on 2022/8/28.
//
#include <vector>
using namespace std;
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
    TreeNode* helper(vector<int>& preorder,int left,int right){
        if (left>right)
            return nullptr;
        int root=preorder[left];
        int mid=root;
        for (; mid < right;mid++) {
            if (preorder[mid]>root) break;
        }
        TreeNode* node= new TreeNode(root);
        node->left= helper(preorder,left+1,mid-1);
        node->right= helper(preorder,mid,right);
        return node;
    }
    void insertTree(TreeNode* &root,int val){
        if (!root){
            root=new TreeNode(val);
            return;
        }

        if (val<root->val)
            insertTree(root->left,val);
        else
            insertTree(root->right,val);
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root= nullptr;
        for (int i=0;i<preorder.size();i++){
            insertTree(root,preorder[i]);
        }
        return root;
    }
};
