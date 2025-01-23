#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0;
        int j=0;;
        while(i<g.size()){
            auto ind=lower_bound(s.begin()+j,s.end(),g[i])-s.begin();
            cout<<ind<<" "<<i<<endl;
            if(ind>=s.size())
            return cnt;
            j=ind+1;
            cnt++;
            i++;
        }
        return cnt;
    }
};