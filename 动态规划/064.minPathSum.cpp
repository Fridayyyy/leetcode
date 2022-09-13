//
// Created by 86184 on 2022/9/13.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> vec(grid.size(),vector<int>(grid[0].size()));
        vec[0][0]=grid[0][0];
        for (int i = 1; i < grid.size(); ++i) {
            vec[i][0]=grid[i][0]+vec[i-1][0];
        }
        for (int j = 1; j < grid[0].size(); ++j) {
            vec[0][j]=grid[0][j]+vec[0][j-1];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                vec[i][j]= min(vec[i-1][j],vec[i][j-1])+grid[i][j];
            }
        }
        return vec[grid.size()-1][grid[0].size()-1];
    }
};
