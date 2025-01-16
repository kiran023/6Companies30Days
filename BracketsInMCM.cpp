#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
  pair<string,long long> MCM(int i,int j,vector<int> &arr,vector<vector<pair<string,long long>>> &dp){
      if(i==j){
          string c="";
          c+=(char)('A'+(i-1));
            return {c,0};
      }
      
      if(dp[i][j].second!=-1)
      return dp[i][j];
      
      long long maxi=INT_MAX;
      string st="";
      for(int k=i;k<j;k++){
          auto part1=MCM(i,k,arr,dp);
          auto part2=MCM(k+1,j,arr,dp);
          string str= "("+part1.first+part2.first+")";
          long long temp= part1.second+part2.second+(arr[i-1]*arr[k]*arr[j]);
          if(maxi>temp){
              maxi=temp;
              st=str;
          }
      }
      return dp[i][j]={st,maxi};
  }
    string matrixChainOrder(vector<int> &arr) {
        vector<vector<pair<string,long long>>> dp(arr.size(),vector<pair<string,long long>>(arr.size(),{"",-1}));
        auto p=MCM(1,arr.size()-1,arr,dp);
        // cout<<p.first<<p.second;
        return p.first;
    }
};