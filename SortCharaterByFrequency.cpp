#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        string ans;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int cnt=top.first;
            while(cnt--){
                ans.push_back(top.second);
            }
        }
        return ans;
    }
};