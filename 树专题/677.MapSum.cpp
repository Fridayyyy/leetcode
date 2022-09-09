//
// Created by 常贵杰 on 2022/8/27.
//
#include <unordered_map>

using namespace std;
struct TriedNode{
    int val;
    TriedNode* next[26];
    TriedNode(){
        this->val=0;
        for (int i = 0; i < 26; ++i) {
            this->next[i]= nullptr;
        }
    }
};
class MapSum {
private:
    unordered_map<string,int> map;
    unordered_map<string,int> prefixmap;
public:
    MapSum() {
    }
    void insert(string key, int val) {
        int delta=val;
        if(map.count(key)){
            delta-=map[key];
        }
        map[key]=val;
        for(int i=1;i<=key.size();i++)
            prefixmap[key.substr(0,i)]+=delta;
    }
    int sum(string prefix) {
        return prefixmap[prefix];
    }
};
