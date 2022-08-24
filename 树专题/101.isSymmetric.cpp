#include <stack>
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
    bool isSymmetric(TreeNode* root) {
        return helper(root,root);
    }
    bool helper(TreeNode* left,TreeNode* right){
        if (!left&&!right)
        {
            return true;
        }
        if (!left||!right)
        {
            return false;
        }
        if (left->val!=right->val)
        {
            return false;
        }
        return helper(left->left,right->right)&&helper(left->right,right->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        stack<TreeNode*> stack;
        if (!root||(!root->right&&!root->left))
        {
            return true;
        }
        stack.push(root->left);
        stack.push(root->right);
        while (!stack.empty())
        {
            TreeNode* node1=stack.top();
            stack.pop();
            TreeNode* node2=stack.top();
            stack.pop();
            if(!node1&&!node2) continue;
            if ((!node1||!node2)||(node1->val!=node2->val))
            {
                return false;
            }
            stack.push(node1->left);
            stack.push(node2->right);
            stack.push(node1->right);
            stack.push(node2->left);
             
        }
        return true;            
    }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while (!q.empty())
        {
            TreeNode* node1=q.front();q.pop();
            TreeNode* node2=q.front();q.pop();
            if ((!node1||!node2)||(node1->val!=node2->val))
            {
                return false;
            }
            q.push(node1->left);
            q.push(node2->right);

            q.push(node1->right);
            q.push(node2->left);
            
        }
        return true;
        
    }
};