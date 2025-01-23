#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int j=0;
            for(j;j<m;j++){
                if(abs(arr1[i]-arr2[j])<=d)
                break;
            }
            if(j==m)
            cnt++;
        }
        return cnt;
    }
};