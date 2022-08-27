//
// Created by 常贵杰 on 2022/8/25.
//
#include <queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        queue<Node*> queue;
        queue.push(root);
        while (!queue.empty()){
            int size = queue.size();
            for (int i = 0; i < size-1; ++i) {
                Node* node = queue.front();queue.pop();
                if(i<size-1){
                    node->next=queue.front();
                }
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }

        }
        return root;
    }
    Node* connect(Node* root) {
        if (!root)
            return root;
        Node* leftmost=root;
        while (leftmost->left){
            Node* head = leftmost;
            while(head){
                head->left->next=head->right;
                if(head->next){
                    head->right->next=head->next->left;
                }
                head=head->next;
            }
            leftmost=leftmost->left;
        }
        return root;
    }
};