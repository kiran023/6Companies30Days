#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j])
                {
                    ans[i][j]=0;
                    q.push({i,j});
                }
                else ans[i][j]=-1;
            }
        }
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int i=top.first;
            int j=top.second;
            // cout<<i<<" "<<j<<endl;
            for(int k=0;k<4;k++){
                int newX=i+dx[k];
                int newY=j+dy[k];
                if(newX>=0 && newY>=0 && newX<m && newY<n && ans[newX][newY]==-1){
                    ans[newX][newY]=ans[i][j]+1;
                    q.push({newX,newY});
                }
            }
        }
        return ans;

    }
};