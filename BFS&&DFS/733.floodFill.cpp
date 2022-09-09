//
// Created by 常贵杰 on 2022/8/29.
//
#include <vector>
using namespace std;

class Solution {
public:
    int target;
    int temp;
    void helper(vector<vector<int>>& image, int x, int y,int row,int col){
        if (x<0||x>row||y<0||y>col||image[x][y]!=target){
            return;
        }
        image[x][y]=temp;
        if (x>=0&&image[x][y]==target){
            helper(image,x-1,y,row,col);
        }
        if (x<row&&image[x][y]==target){
            helper(image,x+1,y,row,col);
        }
        if (y<col&&image[x][y]==target){
            helper(image,x,y+1,row,col);
        }
        if (y>=0&&image[x][y]==target){
            helper(image,x,y-1,row,col);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        target=image[sr][sc];
        temp=color;

        if (target==temp){
            return image;
        }
        helper(image,sr,sc,row,col);
        return image;
    }
};