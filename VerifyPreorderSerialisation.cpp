#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int i=0;
bool dfs(vector<int>&p){
    int val=p[i];
        i++;
    if(val==-1)
    return true;

        if(i>=p.size())
        return false;

        bool right=false,left=false;

        if(p[i]!=-1){
            right=dfs(p);
            
            if(i>=p.size())
            return false;

            if(p[i]!=-1){
                left=dfs(p);
            }
            else{
                i++;
                left=true;
            } 
        }
        else {
            right=true;
            i++;

            if(i>=p.size())
            return false;

            if(p[i]!=-1){
                left=dfs(p);
            }
            else {
                i++;
                left=true;
             }
        }
        // cout<<val<<" "<<right<<left<<endl;
        return right && left;
}
    bool isValidSerialization(string preorder) {
        vector<int>v;
        int ind=0;
        while(ind<preorder.size()){
            int j=ind;
            if(preorder[ind]=='#'){
                v.push_back(-1);
                j++;
            }
            else {
                while(preorder[j]!=',' && j<preorder.size()){
                    j++;
                }
                string substr=preorder.substr(ind,j-ind);
                int val=stoi(substr);
                v.push_back(val);
            }
            ind=j+1;
        }
        // cout<<str;
        return dfs(v) && i>=v.size();
    }
};