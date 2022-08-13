//
// Created by 常贵杰 on 2022/8/12.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* deleteNode(ListNode* head, int val) {
    if(head->val==val)
        return head->next;
    ListNode* node=head;
    while (head->next->val!=val){
        head=head->next;
    }
    head->next=head->next->next;
    return node;
}