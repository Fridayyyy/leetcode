//
// Created by 常贵杰 on 2022/8/12.
//
#include <vector>
#include <unordered_set>

using namespace std;
int findDuplicate(vector<int>& nums) {
    int slow=0,fast=0;
    while (true){
        slow=nums[slow];
        fast=nums[nums[fast]];
        if (slow==fast)
            break;
    }
    int finder=0;
    while (finder!=slow){
        finder=nums[finder];
        slow=nums[slow];
    }
    return slow;
}