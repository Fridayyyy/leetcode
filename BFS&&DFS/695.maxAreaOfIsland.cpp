//
// Created by 常贵杰 on 2022/8/30.
//
#include <vector>
using namespace std;

class Solution {
public:
    int getArea(vector<vector<int>>& grid,int x,int y){
        if (x<0||y<0||x==grid.size()||y==grid[0].size()||grid[x][y]!=1){
            return 0;
        }
        int temp=grid[x][y];
        grid[x][y]=0;
        int q=0,w=0,e=0,r=0;

        if(x>=0&&temp==1)
            q=getArea(grid,x-1,y);
        if(y>=0&&temp==1)
            w= getArea(grid,x,y-1);
        if(x<grid.size()&&temp==1)
            e= getArea(grid,x+1,y);
        if(y<grid[0].size()&&temp==1)
            r= getArea(grid,x,y+1);
        return q+w+e+r;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxArea=0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j<grid[0].size(); ++j) {
                if (grid[i][j]==1){
                    maxArea= max(maxArea, getArea(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};