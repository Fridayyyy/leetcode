//
// Created by 86184 on 2022/9/10.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==0)
            return 0;
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        int result=dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i]= max(dp[i-1]+nums[i],nums[i]);
            if (dp[i]>result) result=dp[i];
        }
        return result;
    }
};
int main(){
    vector<int> vec;
    for (int i = 0; i < 9; ++i) {
        int val;
        cin>>val;
        vec.push_back(val);
    }
    Solution solution;
    cout<<solution.maxSubArray(vec)<<endl;
}