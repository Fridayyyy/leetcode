//
// Created by 常贵杰 on 2022/8/27.
//
#include <queue>

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
    int findBottomLeftValue(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> queue;
        int res;
        queue.push(root);
        while (!queue.empty()){
            TreeNode* node = queue.front();queue.pop();
            if (node->right)
                queue.push(node->right);
            if (node->left)
                queue.push(node->right);
            res=node->val;
        }
        return res;
    }

    void dfs(TreeNode *root, int height, int &curVal, int &curHeight){
        if (!root)
            return;
        height++;
        dfs(root->left,height,curVal,curHeight);
        dfs(root->right,height,curVal,curHeight);
        if(height>curHeight){
            curHeight=height;
            curVal=root->val;
        }
    }

    int findBottomLeftValue(TreeNode* root){
        int curVal,curHeight=0;
        dfs(root,0,curVal,curHeight);
        return curVal;
    }
};