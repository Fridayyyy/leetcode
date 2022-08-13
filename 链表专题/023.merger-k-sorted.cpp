#include <vector>
#include <queue>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergerTwoLists(ListNode *a,ListNode *b){

}

ListNode* merger(vector<ListNode*> &lists,int l, int r){
    if (l==r) return lists[l];
    if (l>r) return nullptr;

    int mid = (l+r)>>1;
    return mergerTwoLists(merger(lists,l,mid), merger(lists,mid+1,r));
}

struct compare{
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
};
priority_queue<ListNode*,vector<ListNode*>,compare> q;

ListNode* mergeKLists(vector<ListNode*>& lists){
    for(auto node:lists){
        if(node) q.push(node);
    }
    ListNode* head = new ListNode();
    ListNode* tail = head;
    while(!q.empty()){
        ListNode* node=q.top();
        q.pop();
        tail->next=node;
        tail = tail->next;
        if(node->next) q.push(node->next);
    }
    return head->next;
}
int main(){

}

