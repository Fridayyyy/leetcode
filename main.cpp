#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int  x):val(x),left(NULL),right(NULL){}
};

class Solution{
private:
    unordered_map<int,int> index;
public:
    int height(TreeNode* root){
        if (root== NULL){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight==-1||rightHeight==-1|| abs(leftHeight-rightHeight) > 1){
            return -1;
        } else{
            return max(leftHeight,rightHeight) + 1;
        }
    }
    bool isBalanced(TreeNode* root){
        return height(root) >= 0;
    }
    int maxDepth(TreeNode* root){
        if (root== nullptr) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while (!Q.empty()){
            int sz = Q.size();
            while (sz>0){
                TreeNode* node = Q.front();Q.pop();
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                sz--;
            }
            ans++;
        }
        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL||root==q||root==p) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }



    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
    TreeNode*



    vector<TreeNode*> getPath(TreeNode* root,TreeNode* target){
        vector<TreeNode*> path;
        TreeNode* node = root;
        while (node!=target){
            path.push_back(node);
            if (node->val>target->val){
                node = node->left;
            } else{
                node = node->right;
            }
        }
        path.push_back(node);
        return path;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
