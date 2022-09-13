//
// Created by ³£¹ó½Ü on 2022/9/11.
//
#include <vector>
using namespace std;
class Test{
public:
    static int a;
    int b;
    static void aaa(){
        return;
    }
};
class Solution {
public:
    int res;
    int uniquePaths(int m, int n) {
        vector<vector<int>> f(m,vector<int>(n));
        for (int i = 0; i < m; ++i) {
            f[i][0]=1;
        }
        for (int j = 0; j < n; ++j) {
            f[0][j]=1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
    int helper(int right,int bottom,int m,int n){
        if (right>=n&&bottom>=m)
            return 0;
        if (right<n){
            res+= helper(right+1,bottom,m,n)+1;
        }
        if (bottom<m){
            res+= helper(right,bottom+1,m,n)+1;
        }
        return ret;
    }
};
int main(){
    Test test;
    test.aaa()
}