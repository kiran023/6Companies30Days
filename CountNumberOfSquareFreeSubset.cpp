#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
const int N=1e9+7;
vector<int> primes;
bool isValid(int val){
    for(int i=2;i<=5;i++){
        if(val%(i*i)==0)
        return false;
    }
    return true;
}
long long makeMask(long long num){
    long long mask=0;
    for(int i=0;i<10;i++){
        int cnt=0;
        if(num%primes[i]==0){
            cnt++;
            num=num/primes[i];
        }
        if(cnt==1)
        mask= mask | (1<<i) ;
    }
    return mask;
}
long long f(int i,long long mask,vector<int> &nums,vector<vector<long long>> &dp){
    if(i>=nums.size())
    return 1;

    if(dp[i][mask]!=-1)
    return dp[i][mask];

    long long taken=0,notaken=f(i+1,mask,nums,dp) % N;
    // taken
    long long currmask=makeMask(nums[i]);
    if((currmask& mask)==0)
    taken=f(i+1, mask | currmask,nums,dp)%N;

    return dp[i][mask]=(taken+notaken)%N;
}
    int squareFreeSubsets(vector<int>& nums) {
        primes={2,3,5,7,11,13,17,19,23,29};
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(isValid(nums[i]))
            v.push_back(nums[i]);
        }
        vector<vector<long long>> dp(v.size(),vector<long long>(1<<11,-1));
        long long cnt=f(0,0,v,dp);
        return (cnt-1+N)%N;

    }
};