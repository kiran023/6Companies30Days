#include<bits/stdc++.h>
using namespace std;

class DataStream {
public:
int val,k,cnt=0;
    DataStream(int value, int k) {
        val=value;
        this->k=k;
    }
    
    bool consec(int num) {
        if(num==val){
            cnt++;
        }
        else cnt=0;
        if(cnt<k)
        return false;
        return true;
    }
};