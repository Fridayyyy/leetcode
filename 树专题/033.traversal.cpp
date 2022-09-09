//
// Created by 常贵杰 on 2022/8/28.
//
#include <vector>
using namespace std;
class Solution {
public:

    bool helper(vector<int>& postorder,int start,int end){
        if (start>=end) return true;
        int index=start;
        for (; index < end; index++) {
            if (postorder[index]>postorder[end])
                break;
        }
        int mid=index;

        for (; index <end ; ++index) {
            if (postorder[index]< postorder[end])
                break;
        }

        bool left= helper(postorder,start,mid-1);
        bool right= helper(postorder,mid,end-1);
        return index==end&&left&&right;
    }
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size()-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        vector<int> sub;
        int root=INT_MAX;
        for (auto i = postorder.begin(); i < postorder.rend(); ++i) {

        }
    }
};
