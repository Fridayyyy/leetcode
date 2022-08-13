//
// Created by 常贵杰 on 2022/8/13.
//

#include <queue>

using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution{
public:
    queue<Node*> queue;
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node *head1,*pre1,*cur;
        dfs(root);

        while (!queue.empty()){
            cur = queue.front();
            queue.pop();
            if (!pre) head=cur;
            else{
                pre->right=cur;
                cur->left=pre;
                pre=cur;
            }
        }
        head->left=pre;
        pre->right=head;
        return head;

    }
    void dfs1(Node* root){
        if (!root) return;
        dfs(root->left);
        queue.push(root);
        dfs(root->right);
    };

    Node *pre,*head;
    Node* treeToDoublyList1(Node* root){
        if (!root) return root;
        dfs(root);
        head->left=pre;
        pre->right-head;
        return head;
    }
    void dfs(Node* root){
        if (!root) return;
        dfs(root->left);
        if (pre) pre->right=root;
        else head = root;

        root->left=pre;
        pre=root;
        dfs(root->right);
    }
};

