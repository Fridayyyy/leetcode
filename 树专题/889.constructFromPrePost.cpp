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
    TreeNode* helper(vector<int>& preorder,int start1,int end1,vector<int>& postorder,int start2,int end2){
        if (start1>end1)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[start1]);
        if (start1==end1)
            return root;

        int i=start2;
        for (; i <= end2; ++i) {
            if (postorder[i]==preorder[start1+1])
                break;
        }
        int len=i-start2+1;
        root->left= helper(preorder,start1+1,start1+len,postorder,start2,i);
        root->right= helper(preorder,start1+1+len,end1,postorder,start2+len,end2-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return helper(preorder,0,preorder.size()-1,postorder,0,postorder.size()-1);
    }
};