//
// Created by 常贵杰 on 2022/8/29.
//
#include <vector>
using namespace std;

class Solution {
public:
    void helper(vector<vector<char>>& grid,int r,int c){
        int nr=grid.size();
        int nc=grid[0].size();

        grid[r][c]='0';
        if (r-1>=0&&grid[r-1][c]=='1')
            helper(grid,r-1,c);
        if (r+1<nr&&grid[r+1][c]=='1')
            helper(grid,r+1,c);

        if (c-1>=0&&grid[r][c-1]=='1')
            helper(grid,r,c-1);
        if (c+1<nc&&grid[r][c+1]=='1')
            helper(grid,r,c+1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]=='1'){
                    res++;
                    helper(grid,i,j);
                }
            }
        }

        return res;
    }
};