//
// Created by 常贵杰 on 2022/8/13.
//

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Node{
public:
    Node* trieNode[26] = {nullptr};
    int isEnd;
    Node(){
        isEnd=-1;
    };
    ~Node(){
        for (int i = 0; i < 26; i++)
        {
            if (trieNode[i])
            {
                /* code */
                delete trieNode[i];
            }
            
        }
        
    };
};

class Trie{
public:
    Trie(){
        root = new Node();
    };
    ~Trie(){
        delete root;
    };
    void insert(string & word,int index){
        Node* p=root;
        int n=word.size();
        for (int i = 0; i < n; i++)
        {
            /* code */
            int c=word[i]-'a';
            if (!p->trieNode[c])
            {
                /* code */
                p->trieNode[c]=new Node();
            }
            p=p->trieNode[c];
            
        }
        p->isEnd=index;
        
    }
    void getRes(string &str,vector<vector<int>> &res,int start){
        Node* p=root;
        int n=str.size();
        for (int i = 0; i < n; i++)
        {
            /* code */
            int c=str[i]-'a';
            if (p->trieNode[c])
            {
                /* code */
                p=p->trieNode[c];
                if (p->isEnd!=-1)
                {
                    /* code */
                    res[p->isEnd].push_back(start);
                }
                
            }else{
                return;
            }
            
        }
        
    }

private:
    Node * root;
};

class Solution {
public:
	vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        int n=big.size();
        int m=smalls.size();
        Trie* trie=new Trie();

        for (int i = 0; i < m; i++)
        {
            /* code */
            trie->insert(smalls[i],i);
        }
        vector<vector<int>> res(m);
        for (int i = 0; i < n; i++)
        {
            /* code */
            string tmpstr = big.substr(i);
            trie->getRes(tmpstr,res,i);
        }
        return res;
    }
};

class solution{
    vector<int> kmp(string& text,string&  pattern){
        int n=pattern.size();
        int m=text.size();
        vector<int> next(n,-1);

        for (int i = 1; i < n; i++)
        {
            /* code */
            int j=next[i-1];
            while (j!=-1&&pattern[i]!=pattern[j+1])
            {
                /* code */
                j=next[j];
            }
            if (pattern[i]==pattern[j+1])
            {
                /* code */
                next[i]=j+1;
            }
        }
    }
    vector<int> getNext(string pattern){
        int n=pattern.length();
        vector<int> next(n,-1);
        int j=-1;
        for (int i = 1; i < n; i++)
        {
            /* code */
            while (j!=-1&&pattern[i]!=pattern[j+1])
            {
                /* code */
                j=next[j];

            }
            if (pattern[i]==pattern[j+1])
            {
                /* code */
                j++;
            }
            next[i]=j;       
        }
        return next;
    }
    vector<int> multiMatch(string text,string pattern){
        int m=text.length(),n=pattern.length();

        vector<int> next=getNext(pattern);
        vector<int> res;
        int j=-1;
        for (int i = 0; i < m; i++)
        {
            /* code */
            while (j!=-1&&text[i]!=pattern[j+1])
            {
                /* code */
                j=next[j];
            }
            if (text[i]==pattern[j+1])
            {
                /* code */
                j++;
            }
            if (j==n-1)
            {
                /* code */
                res.push_back(i-n+1);
                j=next[j];
            }
          
        }
        return res;        
    }
    vector<vector<int>> multiSearch(string big, vector<string>& smalls){
        vector<vector<int>> res;
        int n=smalls.size();
        for (int i = 0; i < n; i++)
        {
            /* code */
            if (smalls[i]=="")
            {
                /* code */
                res.push_back({});
                continue;
            }
            res.push_back(multiMatch(big,smalls[i]));           
        }
        return res;
        
    }
};