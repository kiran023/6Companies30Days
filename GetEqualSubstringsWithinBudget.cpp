#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i=0,j=0;
        int currsum=0;
        int len=0;
        while(i<=j && j<s.size()){
            currsum+=abs(s[j]-t[j]);
            while(currsum>maxCost){
                currsum-=abs(s[i]-t[i]);
                i++;
            }
            if(currsum<=maxCost)
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};