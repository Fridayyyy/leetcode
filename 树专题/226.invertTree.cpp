//
// Created by 常贵杰 on 2022/8/26.
//
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
    void helper(TreeNode* root){
        if (!root)
            return;
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        helper(root->left)
        helper(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()){
            TreeNode* node = queue.top();queue.pop();
            TreeNode* temp=node->left;
            node->left=node->right;
            node->right=temp;
            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        }
        return root;
    }
};