//
// Created by 常贵杰 on 2022/8/13.
//
#include <vector>
#include <queue>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        mid(root);
        return res;
    }
    void mid(TreeNode* root){
        if (!root)
            return;
        mid(root->left);
        res.push_back(root->val);
        mid(root->right);
    }
};
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;

    while (root||!stk.empty()){
        while (root){
            stk.push(root);
            root=root->left;
        }
        root=stk.top();
        stk.pop();
        res.push_back(root->val);
        root=root->right;
    }
    return res;



    return res;
}