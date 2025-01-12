#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if((i!=0 && nums[i]!=nums[i-1]) || i==0){
                for(int j=i+1;j<n;j++){
                    if((j>i+1 && nums[j]!=nums[j-1] && nums[j]-nums[i]==k) || (j==i+1&& nums[j]-nums[i]==k))
                    cnt++;
                    if(nums[j]-nums[i]>k)
                    break;
                }
            }
            
        }
        return cnt;
    }
};