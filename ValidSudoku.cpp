#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // column
        for(int i=0;i<9;i++){
            vector<int> vis(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                continue;
                vis[board[i][j]-'0']++;
                if(vis[board[i][j]-'0']>=2)
                return false;
            }
        }
        // row
        for(int j=0;j<9;j++){
            vector<int> vis(10,0);
            for(int i=0;i<9;i++){
                if(board[i][j]=='.')
                continue;
                vis[board[i][j]-'0']++;
                if(vis[board[i][j]-'0']>=2)
                return false;
            }
        }
        //3*3 box
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                vector<int>vis(10,0);
                for(int a=i;a<i+3;a++){
                    for(int b=j;b<j+3;b++){
                        if(board[a][b]=='.')
                        continue;
                        vis[board[a][b]-'0']++;
                        if(vis[board[a][b]-'0']>=2)
                        return false;
                    }
                }
            }
        }
        return true;
    }
};