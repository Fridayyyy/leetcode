//
// Created by 常贵杰 on 2022/8/11.
//
#include <stack>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr||headB == nullptr)
        return nullptr;
    ListNode *left = headA,*right = headB;

    while (left != right){
        left = left == nullptr ? headB:left->next;
        right = right == nullptr ? headA:right->next;
    }
    return left;

}

ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
    if (!headA||!headB)
        return nullptr;
    ListNode *left = headA,*right = headB;
    while (left!=right){
        if (left)
        left=left->next;
        right=right->next;
        if (!left->next)
            left->next=headB;
        if (!right->next)
            right->next=headA;

    }
    return nullptr;
}

}
