#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};
bool inRange(int x,int y,int n,int m){
    if(x>=0 && y>=0 && x<n && y<m)
    return true;
    return false;
}
int findAvg(int x,int y,vector<vector<int>>& img,int n,int m){
    long long sum=img[x][y];
    int num=1;
    for(int i=0;i<8;i++){
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(inRange(newx,newy,n,m))
        {
            sum= sum + img[newx][newy];
            num++;
        }
    }
    return sum/num;
}
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=findAvg(i,j,img,n,m);
            }
        }
        return ans;
    }
};