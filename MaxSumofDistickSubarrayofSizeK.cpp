
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        int i=0,j=0;
        unordered_map<int,int>mp;
        long long currSum=0;
        while(i<=j && j<nums.size()){
            mp[nums[j]]++;
            currSum+=nums[j];
            while(mp[nums[j]]>=2 && i<j){
                cout<<nums[i]<<" ";
                currSum-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            while(j-i+1>k && i<j){
                currSum-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            if(j-i+1==k)
            sum=max(sum,currSum);
            j++;
        }
        return sum;
    }
};