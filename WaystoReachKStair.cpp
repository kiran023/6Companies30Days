#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i,int jump,int down,int k,unordered_map<int,unordered_map<int,unordered_map<int,int>>> &dp){
        if(i-k>1)
        return 0;

        if(dp.count(i) && dp[i].count(jump) && dp[i][jump].count(down))
        return dp[i][jump][down];

        int ans=0;

        if(i==k){
            ans+=1;
        }
        ans+=f(i+pow(2,jump),jump+1,1,k,dp);
        if(down && i!=0){
        ans+=f(i-1,jump,0,k,dp);
        }
        return dp[i][jump][down]=ans;
    }
    int waysToReachStair(int k) {
        unordered_map<int,unordered_map<int,unordered_map<int,int>>> dp;
       return f(1,0,1,k,dp);
    }
};