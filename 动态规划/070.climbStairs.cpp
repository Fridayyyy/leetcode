//
// Created by 86184 on 2022/9/13.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n<=2)
            return n;
        vector<int> vec(n+1);
        vec[1]=1;
        vec[2]=2;
        for (int i = 3; i <= n; ++i) {
            vec[n]=vec[n-1]+vec[n-2];
        }
        return vec[n];
    }
};
