//
// Created by 常贵杰 on 2022/8/29.
//
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum=0;
        int cover=0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j]==1){
                    sum++;
                    if(i<grid.size()-1&&grid[i+1][j]==1){
                        cover++;
                    }
                    if (j<grid[0].size()-1&&grid[i][j+1]==1)
                        cover++;
                }

            }
        }
        return sum*4-cover*2;

    }
};