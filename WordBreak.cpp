#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool f(int i,string s,unordered_map<string,int>&mp,vector<int>&dp){
    if(i==s.size())
    return true;

    if(dp[i]!=-1)
    return dp[i];

    for(int k=i;k<s.size();k++){
        string str=s.substr(i,k-i+1);
        if(mp.find(str)!=mp.end()){
            cout<<str<<" ";
            if(f(k+1,s,mp,dp))
            return dp[i]=1;
        }
    }
    return dp[i]=0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_map<string,int>mp;
        for(int i=0;i<wordDict.size();i++){
            mp[wordDict[i]]++;
        }
        vector<int>dp(n,-1);
        return f(0,s,mp,dp);
    }
};