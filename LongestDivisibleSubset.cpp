#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        vector<int>dp(n,1);
        vector<int>ind(n);
        for(int i=0;i<n;i++){
            ind[i]=i;
        }
        int maxi=0;
        int index=0;
        for(int i=0;i<n;i++){
            for(int j=0; j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    // cout<<nums[i]<<" "<<nums[j]<<endl;
                    dp[i]=dp[j]+1;
                    ind[i]=j;
                    if(maxi<dp[i]){
                        maxi=dp[i];
                        index=i;
                    }
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dp[i]<<endl;
        // }
        vector<int>ans;
        while(index!=ind[index]){
            ans.push_back(nums[index]);
            index=ind[index];
        }
        ans.push_back(nums[index]);
        return ans;
    }
};