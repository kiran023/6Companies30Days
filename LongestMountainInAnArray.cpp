#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int findLen(int i,vector<int>& arr){
    int len=0;
    int a=i+1,b=i-1;
    while(a<arr.size() && arr[a]<arr[a-1]){
        a++;
    }
    len+=a-i;
    while(b>=0 && arr[b]<arr[b+1]){
        b--;
    }
    len+=i-b;
    return len-1;
}
    int longestMountain(vector<int>& arr) {
        int maxi=0;
        for(int i=1;i<arr.size()-1;i++){
            // cout<<i<<" ";
            if(arr[i]>arr[i+1] && arr[i]>arr[i-1])
            {
                int len=findLen(i,arr);
                maxi=max(maxi,len);
            }
        }
        return maxi;
    }
};