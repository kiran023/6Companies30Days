#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool isIncreasing(int i,int j,vector<int>& nums){
    if(j<i || i==j)
    return true;

    for(int k=i+1;k<=j;k++){
        if(nums[k-1]>=nums[k])
        return false;
    }
    return true;
}
    int incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isIncreasing(0,i-1,nums) && isIncreasing(j+1,n-1,nums)){
                    if((i-1>=0 && j+1<n && nums[i-1]<nums[j+1]) || (i-1)<0 || (j+1)>=n){
                        cnt++;
                        // cout<<i<<" "<<j<<endl;

                    }

                }
            }
        }
        return cnt;
    }
};