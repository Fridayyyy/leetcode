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
ListNode* rotateRight(ListNode* head, int k) {
    if (k==0||head== nullptr||head->next== nullptr){
        return head;
    }
    ListNode* res,*temp=head;
    int n=1;
    while (temp->next!= nullptr){
        temp=temp->next;
        n++;
    }
    temp->next=head;
    while (n--){
        temp=temp->next;
    }
    res->next=temp->next;
    temp->next= nullptr;
    return res;

}

ListNode* rotateRight1(ListNode* head, int k){
    if(k==0||head== nullptr||head->next== nullptr){
        return head;
    }
    int n=1;
    ListNode* iter=head;
    while (iter->next!= nullptr){
        iter=iter->next;
        n++;
    }

    int add = n-k%n;
    if(add==n){
        return head;

    }
    iter->next=head;
    while (add--){
        iter=iter->next;
    }
    ListNode* ret=iter->next;
    iter->next= nullptr;
    return ret;
}