#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v(n,1);
        int cnt=n;
        int i=0;
        while(cnt>1){
            int num=1;
            while(num<k){
                if(v[i]==1){
                    num++;
                }
                i=(i+1)%n;
            }
            cnt--;
            while(v[i]==0){
                i=(i+1)%n;
            }
            v[i]=0;
            while(v[i]==0){
                i=(i+1)%n;
            }
        }
        for(int j=0;j<n;j++){
            if(v[j]==1)
            return j+1;
        }
        return -1;
    }
};