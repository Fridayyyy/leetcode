//
// Created by 常贵杰 on 2022/8/12.
//
#include <stack>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev= nullptr;
    ListNode* curr=head;

    while (curr){
        ListNode* next = curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

ListNode* reverseList1(ListNode* head){
    if (!head) return head;
    stack<int> stack;
    while (head){
        stack.push(head->val);
        head=head->next;
    }
    ListNode* res = new ListNode(-1);
    ListNode* temp=res;
    while (!stack.empty()){
        res->next=new ListNode(stack.top());
        stack.pop();
    }
    return res->next;
}

ListNode* reverseList2(ListNode* head){
    if (!head) return head;
    stack<ListNode*> stack;
    while (head){
        stack.push(head);
        head=head->next;
    }
    ListNode* res = new ListNode(-1);
    ListNode* temp=res;
    while (!stack.empty()){
        res->next=stack.top();
        stack.pop();
        res=res->next;
    }
    return temp;
}

