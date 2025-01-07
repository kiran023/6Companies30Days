#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>v;
        if(s.size()<=10)
        return {};
        int i=0,j=9;
        unordered_map<string,int>mp;
        while(i<j && j<s.size()){
            string str=s.substr(i,j-i+1);
            mp[str]++;
            j++,i++;
        }
        for(auto i:mp){
            if(i.second>=2)
            v.push_back(i.first);
        }
        return v;
    }
};