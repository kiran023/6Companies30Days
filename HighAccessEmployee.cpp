#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<access.size();i++){
            string name=access[i][0];
            string time=access[i][1];
            mp[name].push_back(time);
        }
        vector<string>ans;
        for(auto x:mp){
            string name=x.first;
            // cout<<name<<" ";
            auto v=x.second;
            if(v.size()<=2)
            continue;
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                string str=v[i];
                int cnt=1;
                // cout<<str<<" ";
                if(str[1]=='9'){
                    str[0]=((str[0]-'0')+1)+'0';
                    str[1]='0';
                }
                else {
                    str[1]=((str[1]-'0')+1)+'0';
                }
                // cout<<str<<endl;
                for(int j=i+1;j<v.size();j++){
                    if(v[j]<str)
                    cnt++;
                    if(cnt>=3)
                    break;
                }
                if(cnt>=3){
                    ans.push_back(name);
                    break;
                }
            }
        }
        return ans;
    }
};