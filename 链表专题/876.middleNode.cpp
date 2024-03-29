//
// Created by 常贵杰 on 2022/8/12.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* middleNode(ListNode* head) {
    ListNode* slow=head;
    ListNode* fast=head;

    while (!fast&&!fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}