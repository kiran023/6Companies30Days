#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]&1;
        }
        map<int,int> mp;
        int cnt=0;
        mp[0]=1;
        long long currsum=0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            long long sum=currsum-k;
            if(mp.find(sum)!=mp.end()){
                cnt+=mp[sum];
            }
            mp[currsum]++;
        }
        return cnt;
    }
};