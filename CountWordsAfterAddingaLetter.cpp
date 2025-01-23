#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int findMask(string s){
    int num=0;
    for(int i=0;i<s.size();i++){
        num=num | (1<<(s[i]-'a'));
    }
    return num;
}
    int wordCount(vector<string>& s, vector<string>& t) {
        unordered_map<int,int>cnt;
        for(int i=0;i<s.size();i++){
            cnt[findMask(s[i])]++;
        }

        int count=0;
        for(int i=0;i<t.size();i++){
            int sz=t[i].size();
            int mask=findMask(t[i]);
            for(int j=0;j<sz;j++){
                int newNum=mask & ~(1<<(t[i][j]-'a'));
                if(cnt.count(newNum)){
                    count++;
                    break;
                }
            }
        }
        return count;

    }
};