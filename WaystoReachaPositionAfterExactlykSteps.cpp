#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
const int N=1e9+7;
int f(int s,int e,int currK,int k,unordered_map<int ,unordered_map<int,long long>>&mp){
    if(currK>k)
    return 0;
    if(s==e && k==currK)
    return 1;
    if(mp.count(s) && mp[s].count(currK))
    return mp[s][currK];

    long long right=f(s+1,e,currK+1,k,mp);
    long long left=f(s-1,e,currK+1,k,mp);
    return mp[s][currK]=(left+right)%N;

}
    int numberOfWays(int startPos, int endPos, int k) {
        unordered_map<int ,unordered_map<int,long long>>mp;
        return f(startPos,endPos,0,k,mp);
    }
};