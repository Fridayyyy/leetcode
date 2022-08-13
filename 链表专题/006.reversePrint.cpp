//
// Created by 常贵杰 on 2022/8/12.
//
#include <vector>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

using namespace std;
vector<int> reversePrint(ListNode* head) {
    stack<int> s;
    vector<int> res;
    while (head){
        s.push(head->val);
        head=head->next;
    }
    while (!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}