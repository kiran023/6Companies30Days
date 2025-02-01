#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
const int N=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>dp(n+1,0);
        dp[1]=1;
        for(int i=1;i<=n;i++){
            if(dp[i]==0) continue;
            for(int j=i+delay;j<min(i+forget,n+1);j++){
                dp[j]=(dp[j]+dp[i])%N;
            }
        }
        long long cnt=0;
        for(int i=n;i>max(n-forget,0);i--){
            cnt=(cnt+dp[i])%N;
        }
        return cnt;
    }
};