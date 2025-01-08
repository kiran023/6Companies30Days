#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool isValid(int i,int j,int n,int m){
    if(i<n && j<m && i>=0 && j>=0)
    return true;
    return false;
}
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
            }
        }
        int time=0;
        while(!q.empty()){
            auto top=q.front();
            int x=top[0];
            int y=top[1];
            int t=top[2];
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(isValid(newX,newY,n,m) && grid[newX][newY]==1){
                    q.push({newX,newY,t+1});
                    grid[newX][newY]=2;
                }
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                return -1;
            }
        }
        return time;
    }
};