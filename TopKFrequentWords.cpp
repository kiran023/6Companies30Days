#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
class Compare {
public:
    bool operator()(pair<int,string>&a, pair<int,string>&b)
    {
        if(a.first==b.first)
        return a.second>b.second;
        return a.first<b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare>pq;
        for(auto x:words){
            mp[x]++;
        }
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        vector<string>v;
        while(k--){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }

};