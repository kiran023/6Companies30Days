#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<vector<int>> v;
        for(int i=0;i<a.size();i++){
            v.push_back({(a[i]+b[i]),a[i],b[i]});
        }
        int alice=0,bob=0;
        sort(v.begin(),v.end(),greater<vector<int>>());
        for(int i=0;i<a.size();i++){
            if(i%2==0){
                alice+=v[i][1];
            }
            else bob+=v[i][2];
        }
        if(alice==bob)
        return 0;
        if(alice>bob)
        return 1;
        return -1;
    }
};