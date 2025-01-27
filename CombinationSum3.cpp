#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>> ans;
void f(int ind,int sum,int k,int n,vector<int>&curr){
    if(curr.size()==k && sum==n){
        ans.push_back(curr);
        return ;
    }
    if(curr.size()==k || sum==n)
    return;

    for(int i=ind;i<=9;i++){
        curr.push_back(i);
        f(i+1,sum+i,k,n,curr);
        curr.pop_back();
    }

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        f(1,0,k,n,curr);
        return ans;
    }
};