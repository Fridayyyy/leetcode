struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int val1=0,val2=0,carry=0,cur=0;
    ListNode* res = new ListNode(-1);
    ListNode* temp = res;
    while (l1 != nullptr||l2 != nullptr){
        val1=0;val2=0;
        if (l1){
            val1=l1->val;
            l1=l1->next;
        }
        if(l2){
            val2=l2->val;
            l2=l2->next;
        }
        cur=val2+val1+carry;
        carry=cur/10;
        cur%=10;
        temp->next=new ListNode(cur);
        temp=temp->next;
    }
    if(carry!= 0){
        temp->next = new ListNode(carry);
    }
    return res->next;
}

