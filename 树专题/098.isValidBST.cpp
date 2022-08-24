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
    bool isValidBST(TreeNode* root) {
        return isValid(root,nullptr,nullptr);
    }
    bool isValid(TreeNode* root,TreeNode* treeMax,TreeNode* treeMin){
        if (!root)
        {
            /* code */
            return true;
        }
        if (treeMax&&root->val>=treeMax->val)
        {
            /* code */
            return false;
        }
        if (treeMin&&root->val<=treeMin->val)
        {
            /* code */
            return false;
        }
        return isValid(root->left,root,treeMin)&&isValid(root->right,treeMax,root);
    }



    long long last = LONG_LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root)
        {
            /* code */
            return true;
        }
        bool l = isValidBST(root->left);

        if (root->val<=last)
        {
            /* code */
            return false;
        }
        last=root->val;
        bool r=isValidBST(root->right);
        return l&&r;
    }

    
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = LONG_LONG_MIN;
        while (root&&!stack.empty())
        {
            /* code */
            while (root)
            {
                /* code */
                stack.push(root);
                root=root->left;
            }
            root=stack.top();
            stack.pop();
            if (root->val<=inorder)
            {
                /* code */
                return false;
            }
            inorder=root->val;
            root=root->right;
            
        }
        return true;
        
    }
};