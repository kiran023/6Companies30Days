#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxi=0;
        while(i<=j &&j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                while(i<j &&  mp[nums[j]]>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                    i++;
                }
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};