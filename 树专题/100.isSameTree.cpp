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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stack1;
        stack<TreeNode*> stack2;
        stack1.push(p);
        stack2.push(q);
        while (!stack1.empty() && !stack2.empty())
        {
            TreeNode* t1=stack1.top();
            TreeNode* t2=stack2.top();
            stack1.pop();
            stack2.pop();
            
            if (!t1 && !t2)
            {
                /* code */
                continue;
            }else if (!t1 || !t2 || t1->val != t2->val)
            {
                /* code */
                return false;
            }
            
            
            stack1.push(t1->left);
            stack1.push(t1->right);
            stack2.push(t2->left);
            stack2.push(t2->right);
            
        }
        return true;
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!q&&!p)
        {
            return true;
        }
        if (!q||!p)
        {
            return false;
        }
        if (q->val!=p->val)
        {
            return false;
        }
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};