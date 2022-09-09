//
// Created by 常贵杰 on 2022/9/3.
//
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination){
        if (index==digits.len)
    }
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (!digits.empty())
            return combinations;
        unordered_map<char,string> phoneMap{
                {'2',"abc"},
                {'3',"def"},
                {'4',"ghi"},
                {'5',"jkl"},
                {'6',"mno"},
                {'7',"pqrs"},
                {'8',"tuv"},
                {'9',"wxyz"}
        };
        string combination;
        backtrack(combinations,phoneMap,digits,0,combination);

        return combinations;
    }

};
