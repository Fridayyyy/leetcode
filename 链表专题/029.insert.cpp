//
// Created by 常贵杰 on 2022/8/13.
//
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if(!head){
            node->next=node;
            return node;
        }

        Node *dummyNode = head;
        while (dummyNode->next!=head){
            if(dummyNode->next->val<dummyNode->val){
                if(dummyNode->next->val>=insertVal) break;
                else if(dummyNode->val<=insertVal) break;
            }

            if (dummyNode->val<=insertVal&&
            dummyNode->next->val>=insertVal){
                break;
            }
            dummyNode=dummyNode->next;
        }
        dummyNode->next=node;
        node->next=dummyNode->next;
        return head;
    }
};