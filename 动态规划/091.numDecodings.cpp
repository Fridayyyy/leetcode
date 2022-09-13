//
// Created by 86184 on 2022/9/13.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> f(n+1);
        f[0]=1;
        for (int i = 1; i <=n ; ++i) {
            if (s[i-1]!='0')
                f[i]=f[i-1];
            if (i>=2){
                int t=(s[i-2]='0')*10+s[i-1]-'0';
                if (t>=10&&t<=26) f[i]+=f[i-2];
            }
        }
        return f[n];
    }
    int numDecodings1(string s) {
        if (s.empty()||s[0]=='0')
            return 0;
        int a=0,b=1,c;
        for (int i = 1; i <=s.size() ; ++i) {
            c=0;
            if (s[i-1]!='0'){
                c+=b;
            }
        }
    }

};
