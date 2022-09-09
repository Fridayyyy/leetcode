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
    vector<vector<int>> res;
    vector<int> path;

    void helper(TreeNode* root, int target){
        if (!root)
            return nullptr;
        path.emplace_back(root->val);
        target-=root->val;
        if (!root->left&&!root->right&&target==0)
            res.emplace_back(path);

        helper(root->left,target);
        helper(root->right,target);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int target) {
        helper(root,target);
        return res;
    }
};
