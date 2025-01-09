#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int sellBuy(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>>&dp){
    // cout<<i<<buy<<curr<<endl;
    if(i>=prices.size() || k==0){
        return 0;
    }

    if(dp[i][buy][k]!=-1)
    return dp[i][buy][k];

    if(buy){
        return dp[i][buy][k]=max(sellBuy(i+1,buy,k,prices,dp),
        sellBuy(i+1,0,k,prices,dp)-prices[i]);
    }
    else{
        return dp[i][buy][k]=max(sellBuy(i+1,buy,k,prices,dp),
        sellBuy(i+1,1,k-1,prices,dp)+prices[i]);
    }
}
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        // int maxi=INT_MIN;
        return sellBuy(0,1,k,prices,dp);
        // return maxi;
    }
};