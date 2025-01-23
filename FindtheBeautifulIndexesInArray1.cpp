#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void findZ(string &s,vector<int>&z){
    int l=0,r=0;
    for(int i=1;i<s.size();i++){
        if(i>r){
            l=r=i;
            while(r<s.size() && s[r-l]==s[r]){
                r++;
            }
            z[i]=r-l;
            r--;
        }
        else {
            int k=i-l;
            if(z[k]<r-i+1){
                z[i]=z[k];
            }
            else{
                l=i;
                while(r<s.size() &&s[r-l]==s[r]){
                    r++;
                }
                z[i]=r-l;
                r--;
            }
        }
    }
}
vector<int> findIndx(string &s,int n,int m){
    vector<int>Z(s.size());
    findZ(s,Z);
    vector<int>ans;
    for(int i=0;i<Z.size();i++){
        // cout<<Z[i]<<" ";
        if(Z[i]==n)
            ans.push_back(i-n-1);
    }
    // cout<<endl;
    return ans;
}
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>ans;
        string str=a+"#"+s;
        vector<int> indx1=findIndx(str,a.size(),s.size());
        string str2=b+"#"+s;
        vector<int> indx2=findIndx(str2,b.size(),s.size());
        for(int i=0;i<indx1.size();i++){
           for(int j=0;j<indx2.size();j++){
                if(abs(indx1[i]-indx2[j])<=k){
                    ans.push_back(indx1[i]);
                    break;
                }
           }
        }
        return ans;
        
    }
};