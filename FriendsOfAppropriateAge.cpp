#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& age) {
        int cnt=0;
        vector<int>v(121,0);
        for(int i=0;i<age.size();i++){
            v[age[i]]++;
        }
        for(int i=1;i<121;i++){
            for(int j=0;j<i;j++){
                if( v[i] && v[j] && j>((0.5*i)+7))
                cnt+=v[i]*v[j];
            } 
            if(v[i]>1 && i>((0.5*i)+7))
                cnt+= v[i]*(v[i]-1);
        }
        return cnt;
    }
};