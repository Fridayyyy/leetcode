#include <vector>
#include <deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) 
        {
            deque<int> levelList;
            int size = nodeQueue.size();
            
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                if (isOrderLeft)
                {
                    levelList.push_back(node->val);
                }else
                {
                    levelList.push_front(node->val);
                }
                if (node->left)
                {
                    nodeQueue.push(node->left);
                }
                if (node->right)
                {
                    nodeQueue.push(node->right);
                }
            }
            res.emplace_back(vector<int>{levelList.begin(),levelList.end()});
            
            isOrderLeft=!isOrderLeft;
        }
        return res;


    }
};