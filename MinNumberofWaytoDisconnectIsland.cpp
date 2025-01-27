#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void dfs(int i,int j,vector<vector<int>>& grid,int n,int m){
    grid[i][j]=0;
    for(int a=0;a<4;a++){
        int newX=i+dx[a];
        int newY=j+dy[a];
        if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1){
            dfs(newX,newY,grid,n,m);
        }
    }
}
int isValid(vector<vector<int>> grid,int n,int m){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                cnt++;
                dfs(i,j,grid,n,m);
            }
        }
    }
    return cnt;
}
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=isValid(grid,n,m);
        if(cnt==0 || cnt>1)
        return 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    int num=isValid(grid,n,m);
                    grid[i][j]=1;
                    if(num>1 || num==0)
                    return 1;
                }
            }
        }

        return 2;
    }
};