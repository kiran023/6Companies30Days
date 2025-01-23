#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int maxLen(vector<int>nums){
    int n=nums.size();
    int maxi=1;
    int prev=0;
    int len=1;
    for(int i=1;i<n;i++){
        if(nums[i]-nums[prev]==1){
            prev=i;
            len++;
            maxi=max(maxi,len);
        }
        else {
            len=1;
            prev=i;
        }
    }
    return maxi;

}
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int maxiH=maxLen(hBars);
        int maxiV=maxLen(vBars);
        // cout<<maxiH<<" "<<maxiV;
        int miniAll=min(maxiV,maxiH)+1;
        return miniAll*miniAll;
    }

};