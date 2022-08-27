//
// Created by 常贵杰 on 2022/8/25.
//
#include <vector>
#include <queue>
#include <stack>
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
    void preorder(TreeNode* root){
        if(!root)
            return;
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        if (!root)
            return;
        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev= nullptr;
        while (!stk.empty()){
            TreeNode* curr=stk.top();stk.pop();
            if (prev){
                prev->left= nullptr;
                prev->right=curr;
            }
            TreeNode* left=curr->left,*right=curr->right;
            if(right)
                stk.push(right);
            if(left)
                stk.push(left);
            prev=curr;
        }
    }
    void flatten(TreeNode* root) {
        if (!root)
            return;
        queue<TreeNode*> queue;
        queue.push(root);
        TreeNode* prev= nullptr;
        while (!queue.empty()){
            TreeNode* node = queue.front();queue.pop();

            if (prev){
                prev->left= nullptr;
                prev->right=node;
            }

            if (node->left)
                queue.push(node->left);
            if (node->right)
                queue.push(node->right);
            prev=node;
        }
    }
};
