#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
string ans="";
unordered_map<char,int>mp;
void f(int i,string &s,string &str){
    if(i==s.size())
    {
        if(ans!="")
        return ;
        ans=str;
        return;
    }
    char c=s[i];
    if(c=='D'){
        char prev=str[str.size()-1];
        for(char j=prev-1;j>='1';j--){
            if(!mp.count(j)){
                // cout<<j<<" ";
                str.push_back(j);
                mp[j]++;
                f(i+1,s,str);
                str.pop_back();
                mp.erase(j);
            }
       }
    }
    else {
        char prev=str[str.size()-1];
        for(char j=prev+1;j<='9';j++){
            if(!mp.count(j)){
                // cout<<j<<" ";
                str.push_back(j);
                mp[j]++;
                f(i+1,s,str);
                str.pop_back();
                mp.erase(j);
            }
       }
    }
    
}
    string printMinNumberForPattern(string s){
        string str="";
        for(char c='1';c<='9';c++){
            str.push_back(c);
            mp[c]++;
            f(0,s,str);
            if(ans!=""){
                break;
            }
            str.pop_back();
            mp.erase(c);
        }
        return ans;
    }
};