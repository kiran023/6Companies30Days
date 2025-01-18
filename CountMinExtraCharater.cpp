#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int remove (int i,string s,unordered_map<string,int>&mp,unordered_map<int,int>&dp){
    if(i==s.size())
    return 0;

    if(dp.count(i))
    return dp[i];

    // nottaken
    int length=remove(i+1,s,mp,dp)+1;
    // taken
    for(int k=i;k<s.size();k++){
        string str=s.substr(i,k-i+1);
        if(mp.count(str)){
            length=min(length,remove(k+1,s,mp,dp));
        }
    }
    return dp[i]=length;

}
    int minExtraChar(string s, vector<string>& dic) {
        unordered_map<string,int>mp;
        unordered_map<int,int>dp;
        for(int i=0;i<dic.size();i++){
            mp[dic[i]]++;
        }
        return remove(0,s,mp,dp);
    }
};