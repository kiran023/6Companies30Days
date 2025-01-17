#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q){
        int n=nums.size();
        int m=q.size();
        int sSize=nums[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            int trim=q[i][1];
            int k=q[i][0];
            vector<pair<string,int>>v;
            for(int j=0;j<n;j++){
                string str=nums[j].substr(sSize-trim,trim);
                v.push_back({str,j});
            }
            sort(v.begin(),v.end());
            ans.push_back(v[k-1].second);
        }
        return ans;
    }
};