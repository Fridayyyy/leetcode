struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    ListNode* getMedian(ListNode* left,ListNode* right){
        ListNode* slow = left;
        ListNode* fast = left;
        while (fast!=right&&fast->next!=right){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    TreeNode* helper(ListNode* left,ListNode* right){
        if(left==right)
            return nullptr;
        ListNode* mid = getMedian(left,right);
        TreeNode* root = new TreeNode(mid->val);
        root->left= helper(left,mid);
        root->right= helper(mid,right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, nullptr);
    }

    int getLength(ListNode* head){
        int ret=0;
        while (head){
            ret++;
            head=head->next;
        }
        return ret;
    }

    TreeNode* buildTree(ListNode* head,int left,int right){
        if(left>right)
            return nullptr;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(mid);
        root->left= buildTree(head,left,mid-1);
        root->right= buildTree(head,mid+1,right);
        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        int length = getLength(head);
        buildTree(head,0,length-1);
    }

};