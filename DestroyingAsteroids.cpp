#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& ast) {
        long long weight=mass;
        int n=ast.size();
        sort(ast.begin(),ast.end());
        for(int i=0;i<n;i++){
            if(weight>=ast[i])
            weight+=ast[i];
            else return false;
        }
        return true;
    }
};