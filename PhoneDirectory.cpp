#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
bool isExist(string str,string contact){
    if(contact.size()<str.size())
    return false;
    string check=contact.substr(0,str.size());
    return str==check;
}
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ans;
        string str="";
        sort(contact,contact+n);
        for(int i=0;i<s.size();i++){
            str+=s[i];
            vector<string> curr;
            for(int j=0;j<n;j++){
                if(j==0 && isExist(str,contact[j]))
                curr.push_back(contact[j]);
                if(j!=0 && contact[j]!=contact[j-1] && isExist(str,contact[j]))
                curr.push_back(contact[j]);
            }
            if(curr.size()==0)
            curr.push_back("0");
            ans.push_back(curr);
        }
        return ans;
    }
};