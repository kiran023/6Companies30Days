#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string encode(string s) {
        int n=s.size();
        int i=0;
        string ans="";
       while(i<n){
           int j=i+1;
           int cnt=1;
           while(j<n && s[j]==s[j-1]){
               j++;
               cnt++;
           }
           ans+=s[i]+to_string(cnt);
           i=j;
       }
       return ans;
    }
};