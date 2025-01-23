#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void dfs(int i,int j,vector<vector<char>>& board,int n,int m){
    cout<<i<<" "<<j<<endl;

    // horizonal
    for(int k=j+1;k<m;k++){
        if(board[i][k]=='X')
        board[i][k]='#';
        else break;
    }

    //vertical
    for(int k=i+1;k<n;k++){
        if(board[k][j]=='X')
        board[k][j]='#';
        else break;
    }

    board[i][j]='#';

    return ;
}
    int countBattleships(vector<vector<char>>& board) {
        int cnt=0;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X')
                {
                    cnt++;
                    dfs(i,j,board,n,m);
                }
            }
        }
         return cnt;
    }
};