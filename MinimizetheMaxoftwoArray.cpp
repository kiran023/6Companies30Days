#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int LCM(long long div1,long long div2){
    long long mul=div1*div2;
    long long lcm=mul/gcd(div1,div2);
    return lcm>1e9*2 ? 1e9*2:lcm;
}
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        int l=1,r=1e9 *2;
        int lcm=LCM(div1,div2);
        while(l<=r){
            int mid=l+(r-l)/2;
            int a=mid/div1;
            int b=mid/div2;
            if(cnt1<=(mid-a) && cnt2<=(mid-b) && (cnt1+cnt2)<=mid-(mid/lcm))
            r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};