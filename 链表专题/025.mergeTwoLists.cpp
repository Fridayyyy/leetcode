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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head,*tail = &head,*aPtr=l1,*bPtr=l2;
    tail->next = aPtr?aPtr:bPtr;
    while (aPtr||bPtr){
        if(aPtr->val > bPtr->val){
            tail->next = bPtr;
            bPtr = bPtr->next;
        } else{
            tail->next = aPtr;
            aPtr = aPtr->next;
        }
        tail = tail->next;
    }
    return head.next;
}
ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);
    ListNode* tail = head;

    while (l1&&l2){
        if(l1->val < l2->val){
            tail->next=l1;
            l1=l1->next;
        } else{
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    tail->next = l1?l1:l2;
    return head->next;
}
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2){
    ListNode* preHead = new ListNode(-1);

    ListNode* prev = preHead;

    while (l1&&l2){
        if (l1->val<l2->val){
            prev->next=l1;
            l1=l1->next;
        } else{
            prev->next=l2;
            l2=l2->next;
        }
        prev=prev->next;
    }
    prev->next = !l1?l2:l1;
    return preHead->next;
}