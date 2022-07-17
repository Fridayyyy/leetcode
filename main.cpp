#include <iostream>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int  x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    bool isBalanced(TreeNode* root){

    }
    int maxDepth(TreeNode* root){
        if (root== nullptr) return 0;
        queue<TreeNode*> Q;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
