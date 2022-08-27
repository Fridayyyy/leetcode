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
    int helper(TreeNode* node){
        if(!node)
            return 0;
        return min(helper(node->left), helper(node->right))+1;
    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left&&!root->right){
            return 1;
        }
        int min_depth = INT_MAX;
        if(root->left){
            min_depth=min(minDepth(root->left),min_depth);
        }
        if(root->right){
            min_depth= min(minDepth(root->right),min_depth);
        }
        return min_depth+1;
    }
    int minDepth(TreeNode* root){
        if (!root)
            return 0;

        queue<pair<TreeNode*,int> > que;
        que.push(root,1);
        while (!que.empty()){
            TreeNode* node=que.front().first;
            int depth=que.front().second;

            if(!node->left&&!node->right){
                return depth;
            }
            if(!node->left){
                que.push(root->left,depth+1);
            }
            if(!node->right){
                que.push(root->right,depth+1);
            }
        }
        return 0;
    }
};
