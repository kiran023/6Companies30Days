
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int f(int ind,vector<int>& nums){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        if(i==ind)
        continue;
        sum+=abs(nums[i]-nums[ind]);
    }
    return sum;
}
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%2==0)
        return min(f(n/2,nums),f(n/2-1,nums));
        return f(n/2,nums);
    }
};