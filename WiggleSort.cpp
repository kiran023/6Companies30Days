#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>ans=nums;
        sort(ans.begin(),ans.end());
        int i=1;
        int j=nums.size()-1;
        while(i<nums.size()){
            nums[i]=ans[j];
            i=i+2;
            j--;
        }
        i=0;
        while(i<nums.size()){
            nums[i]=ans[j];
            i=i+2;
            j--;
        }
    }
};