#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        int cnt=0;
        map<vector<int>,int>mp;
        for(int i=0;i<n;i++){
            int divCnt=0;
            vector<int>v;
            for(int j=i;j<n;j++){
                if(nums[j]%p==0){
                    divCnt++;
                }
                v.push_back(nums[j]);
                if(divCnt<=k){
                    cnt++;
                    mp[v]++;
                }
                else break;
            }
        }
        cout<<cnt;
        for(auto x:mp){
            if(x.second>=2){
                cnt-=x.second-1;
            }
        }
        return cnt;
    }
};