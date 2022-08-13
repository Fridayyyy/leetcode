//
// Created by 常贵杰 on 2022/8/10.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *detectCycle(ListNode *head) {
    if(!head||!head->next||!head->next->next){
        return nullptr;
    }
    ListNode *slow=head,*fast=head;
    while (fast!=slow&&fast){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(!fast||!fast->next) return nullptr;

    while (head!=fast){
        head=head->next;
        fast=fast->next;
    }
    return head;
}