#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int i=v.size()-1;
        map<int,int>mp;
        vector<int>ans;
        while(i>=0 && k){
            mp[v[i].second]=v[i].first;
            i--,k--;
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};