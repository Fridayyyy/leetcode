//
// Created by 86184 on 2022/9/10.
//
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        dfs(n,0,0,"");
        return res;
    }
    void dfs(int n,int lc,int rc,string str){
        if (rc==n&&lc==n){
            res.push_back(str);
        } else{
            if (lc<n) dfs(n,lc+1,rc,str+"(");
            if (rc<n&&lc>rc) dfs(n,lc,rc+1,str+")");
        }
    };
};