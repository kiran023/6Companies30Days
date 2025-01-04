#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<int>> rect;
vector<int> v;
int totalArea=0;
int area(int x1,int y1,int x2,int y2){
    return (x2-x1+1)*(y2-y1+1);
}
    Solution(vector<vector<int>>& rects) {
        this->rect=rects;
        for(int i=0;i<rects.size();i++){
            totalArea+=area(rects[i][0],rect[i][1],rect[i][2],rect[i][3]);
            v.push_back(totalArea);
        }
    }
    
    vector<int> pick() {
        int num=rand()%totalArea;
        int ind;
        for(int i=0;i<v.size();i++){
            if(num<v[i])
            {
                ind=i;
                break;
            }
        }
        auto r=rect[ind];
        int x= r[0]+ rand()%(r[2]-r[0]+1);
        int y= r[1]+ rand()%(r[3]-r[1]+1);
        return {x,y};
    }
};