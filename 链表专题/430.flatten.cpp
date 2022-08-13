//
// Created by 常贵杰 on 2022/8/12.
//
#include <stack>

using namespace std;
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
class Solution{

public:
    Node* flatten(Node* head){
        Node* p = head;
        while (p){
            if(p->child){
                Node* start=p->child;
                Node* end=start;
                while (end && end->next){
                    end=end->next;
                }
                if(p->next){
                    p->next->prev = end;
                }
                end->next=p->next;

                p->next=start;
                p->child= nullptr;
                start->prev=p;
            }
            p=p->next;
        }
        return head;
    }

    Node* flatten1(Node* head) {
        Node* node = head;
        stack<Node*> s;
        while (node!= nullptr){
            if (node->child){
                if (node->next){
                    s.push(node->next);
                }
                Node* child=node->child;
                node->next=child;
                child->prev=node;
                node->child= nullptr;
            }
            if (!node->next&&!s.empty()){
                Node* next=s.top();
                s.pop();
                node->next=next;
                node->prev=node;
            }
            node=node->next;
        }
        return head;
    }
    Node* flatten2(Node* head) {
        if (!head) return head;
        Node* node=head;

        while (node){
            if (node->child){
                Node* next = node->next;
                Node* child= flatten(node->child);
                node->next=child;
                child->prev=node;
                node->child= nullptr;

                if (next){
                    while (node->next){
                        node=node->next;
                    }
                    node->prev=next;
                    next->prev=node;
                }
            }
            node=node->next;
        }
        return head;
    }

};