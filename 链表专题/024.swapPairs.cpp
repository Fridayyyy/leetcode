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
ListNode* swapPairs(ListNode* head) {
    if(head== nullptr||head->next== nullptr){
        return head;
    }

    ListNode* newHead = head->next;
    head->next= swapPairs(newHead->next);
    newHead->next=head;

    return newHead;
}

ListNode* swapPairs1(ListNode* head) {
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next=head;
    ListNode* temp=dummyHead;

    while (temp->next!= nullptr&&temp->next->next!= nullptr){
        ListNode* node1=temp->next;
        ListNode* node2=temp->next->next;

        temp->next=node2;
        node2->next=node1;
        node1->next=node2->next;
        temp=node1;
    }
    return dummyHead->next;
}