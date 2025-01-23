#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void findZ(string &s,vector<int>&z){
    int l=0,r=0;
    int n=s.size();
    for(int i=1;i<n;i++){
        if(i>r){
            l=i,r=i;
            while(r<n && s[r-l]==s[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
        else {
            int ind=i-l;
            if(z[ind]<r-i+1){
                z[i]=z[ind];
            }
            else{
                l=i;
                while(r<n && s[r-l]==s[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }
    }
}
    long long sumScores(string s) {
        int n=s.size();
        vector<int>Z(n);
        findZ(s,Z);
        long long ans=0;
        for(int i=0;i<n;i++){
            ans+=Z[i];
        }
        return ans+n;
    }
};