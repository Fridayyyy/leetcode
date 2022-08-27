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
    int helper(TreeNode* root,int i){
        if (!root)
            return 0;
        int temp=i*10+root->val;
        if(!root->left&&!root->right)
            return temp;
        return helper(root->left,temp)+helper(root->right,temp);
    }
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
    int sumNumser(TreeNode* root){
        if (!root)
            return 0;
        int sum=0;
        queue<TreeNode> nodeQueue;
        queue<int> numQueue;
        nodeQueue.push(root);
        numQueue.push(root->val);
        while (!nodeQueue.empty()){
            TreeNode* node = nodeQueue.front();
            int num=numQueue.front();
            nodeQueue.pop();
            numQueue.pop();
            TreeNode* left=node->left;
            TreeNode* right=node->right;
            if(!left&&!right)
                sum+=num;
            else{
                if(left){
                    nodeQueue.push(left);
                    numQueue.push(num*10+left->val);
                }
                if(right){
                    nodeQueue.push(right);
                    numQueue.push(num*10+right->val);
                }
            }
        }
        return sum;
    }
};
