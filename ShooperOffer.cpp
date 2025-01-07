#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void f(int i,vector<vector<int>>& special,vector<int>&needs,vector<int> &price,int specialsum,int totalsum, int &mini){
    if(i>=special.size() || totalsum==0){
        // cout<<specialsum<<" "<<totalsum<<endl;
       mini= min(specialsum+totalsum,mini);
       return;
    }
    

    //nottaken
    f(i+1,special,needs,price,specialsum,totalsum,mini);

    bool cantake=true;
    for(int j=0;j<special[i].size()-1;j++){
        if(special[i][j]>needs[j]){
            cantake=false;
            break;
        }
        if(special[i][j]<=needs[j]){
            totalsum-=price[j]*special[i][j];
        }
    }

    //taken
    if(cantake){
        specialsum+=special[i][needs.size()];
        for(int j=0;j<needs.size();j++){
            needs[j]=needs[j]-special[i][j];
        }
        f(i,special,needs,price,specialsum,totalsum,mini);
        for(int j=0;j<needs.size();j++){
            needs[j]=needs[j]+special[i][j];
        }
    }
    return ;
}
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int mini=INT_MAX;
        int totalsum=0;
        int n=needs.size();
        for(int i=0;i<needs.size();i++){
            totalsum+=needs[i]*price[i];
        }
        // cout<<totalsum;
        f(0,special,needs,price,0,totalsum,mini);
        return mini;
    }
};