//
// Created by 常贵杰 on 2022/8/12.
//
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> stack1,stack2;

    while (l1){
        stack1.push(l1->val);
        l1=l1->next;
    }
    while (l2){
        stack2.push(l2->val);
        l2=l2->next;
    }
    int carry=0;
    ListNode* ans = nullptr;

    while (!stack1.empty() or carry!=0 or !stack2.empty()){
        int a = stack1.empty()?0:stack1.top();
        int b = stack2.empty()?0:stack2.top();
        if (!stack1.empty()) stack1.pop();
        if (!stack2.empty()) stack2.pop();
        int cur=a+b+carry;
        carry=cur/10;
        cur%=10;
        auto curnode = new ListNode(cur);
        curnode->next=ans;
        ans=curnode;
    }
    return ans;
}