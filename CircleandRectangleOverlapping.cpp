#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int findCoordinate(int x1,int x2 ){
    if((x1<0 && x2>=0) || (x2<0 && x1>=0))
    return 0;
    if(x1<0 && x2<0)
    return max(x1,x2);
    return min(x1,x2);
}
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        x1=x1-xCenter;
        y1=y1-yCenter;
        x2=x2-xCenter;
        y2=y2-yCenter;
        int nearestX=findCoordinate(x1,x2);
        int nearestY=findCoordinate(y1,y2);
        return nearestX*nearestX+nearestY*nearestY<=radius*radius;
    }
};