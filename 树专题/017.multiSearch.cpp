//
// Created by 常贵杰 on 2022/8/13.
//

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode{
    int sid;
    TrieNode* next[26];
    TrieNode(){
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }
};

class Solution{
private:
    TrieNode* root=new TrieNode();
    void insert(string small_str,int sid){
        TrieNode* node = root;
        for (int i = 0; i < small_str.size(); ++i) {
            int ind=small_str.at(i)-'a';
            if (node->next[ind]== nullptr)
                node->next[ind] = new TrieNode();
            node=node->next[ind];
        }
        node->sid=sid;
    }
    void search(string big_str,vector<vector<int>>& ans,int bid){
        TrieNode* node = root;
        for (int i = 0; i < big_str.size(); ++i) {
            int ind=big_str.at(i)-'a';
            if (node->sid!=-1)
                ans[node->sid].emplace_back(bid);

            if (!node->next[ind])
                return;
            node=node->next[ind];
        }
        if (node->sid!=-1){
            ans[node->sid].emplace_back(bid);
        }
    }
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> ans(smalls.size(),vector<int>());
        for (int i = 0; i < smalls.size(); ++i) {
            if (smalls[i].size()==0){
                continue;
            }
            insert(smalls[i],i);
        }
        for (int i = 0; i < big.size(); ++i) {
            string big_str=big.substr(i,big.size()-i);
            search(big_str,ans,i);
        }
        return ans;
    }
};