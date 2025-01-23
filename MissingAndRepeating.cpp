#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int x=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            x^=arr[i];
            x^=(i+1);
        }
        int rightMostSetBit= x & ~(x-1);
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(arr[i] & rightMostSetBit)
            a^=arr[i];
            else b^=arr[i];
        }
        for(int i=1;i<=n;i++){
            if(i & rightMostSetBit)
            a^=i;
            else b^=i;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(arr[i]==a)cnt++;
        }
        if(cnt==2) return {a,b};
        return {b,a};
    }
};