#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int f(int i,int j,vector<int>& nums1,vector<int>&nums2,vector<vector<int>> &dp){
    if(i>=nums1.size() || j>=nums2.size() || nums1[i]!=nums2[j])
        return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];

    return dp[i][j]=1+f(i+1,j+1,nums1,nums2,dp);
}
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]].push_back(i);
        }
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size(),-1));
        int maxi=0;
        for(int i=0;i<nums1.size();i++){
            if(mp.find(nums1[i])!=mp.end()){
                for(auto j:mp[nums1[i]]){
                    int curr=f(i,j,nums1,nums2,dp);
                    maxi=max(maxi,curr);
                }
            }
        }
        return maxi;
    }
};