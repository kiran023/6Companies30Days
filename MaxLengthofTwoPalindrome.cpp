#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
bool ispal(string &s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])
        return false;
        i++,j--;
    }
    return true;
}

void dfs(string &s1,string &s2,int i,string &s,int &maxi){
    if(i==s.size()){
        if(ispal(s1) && ispal(s2)){
            int pro=s1.size()*s2.size();
        maxi=max(maxi,pro);
        }
        return;
    }

    dfs(s1,s2,i+1,s,maxi);

    s1.push_back(s[i]);
    dfs(s1,s2,i+1,s,maxi);
    s1.pop_back();

    s2.push_back(s[i]);
    dfs(s1,s2,i+1,s,maxi);
    s2.pop_back();

}

    int maxProduct(string s) {
        int maxi=0;
        string s1="",s2="";
        dfs(s1,s2,0,s,maxi);
        return maxi;
    }
};