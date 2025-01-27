#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>>v;
int m,n;
unordered_map<int,vector<int>> mp;
    Solution(int m, int n) {
        v.resize(m,vector<int>(n,0));
        this->m=m;
        this->n=n;
    }
    
    vector<int> flip() {
        int randI=rand()%m;
        int randJ=rand()%n;
        while(v[randI][randJ]!=0){
            randI=rand()%m;
            randJ=rand()%n;
        }
        v[randI][randJ]=1;
        mp[randI].push_back(randJ);
        return {randI,randJ};
    }
    
    void reset() {
        for(auto x:mp){
            int i=x.first;
            auto vec=x.second;
            for(int a=0;a<vec.size();a++){
                v[i][vec[a]]=0;
            }
        }
    }
};