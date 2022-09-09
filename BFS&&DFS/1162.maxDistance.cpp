//
// Created by 常贵杰 on 2022/9/3.
//
#include <vector>
using namespace std;
class Solution {
public:
    int helper(vector<vector<int>>& grid,int i,int j){
        if (i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=1)
            return 0;
        int q=0,w=0,e=0,r=0;
        if (0<=i&&grid[i][j]==0){
            q= helper(grid,i-1,j);
        }
        if (0<=j&&grid[i][j]==0){
            w= helper(grid,i,j-1);
        }
        if (grid.size()>i&&grid[i][j]==0){
            e= helper(grid,i+1,j);
        }
        if (grid[0].size()>j&&grid[i][j]==0){
            r= helper(grid,i,j+1);
        }
        return min({(int)q,w,e,r})+1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int maxDis=-1;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]==0){
                    maxDis= max(maxDis, helper(grid,i,j));
                }
            }
        }
        return maxDis;
    }
};