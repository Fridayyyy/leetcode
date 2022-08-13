//
// Created by 常贵杰 on 2022/8/12.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* slow=head;
    ListNode* fast=head;
    for (int i = 0; i < k; ++i) {
        fast=fast->next;
    }
    while (fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}