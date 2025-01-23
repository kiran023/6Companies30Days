#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int dp[51][51][51][4];
int f(int x,int y,int z,int prev){
    if(dp[x][y][z][prev]!=0)
    return dp[x][y][z][prev];

    int x1=0,y1=0,z1=0;
    if(prev!=1 && x>0)
    x1=2+f(x-1,y,z,1);

    if(prev!=3 && prev!=2 && y>0)
    y1=2+f(x,y-1,z,2);

    if(prev!=1 && z>0)
    z1=2+f(x,y,z-1,3);

    return dp[x][y][z][prev]=max(x1,max(y1,z1));

}
    int longestString(int x, int y, int z) {
        return f(x,y,z,0);

    }
};