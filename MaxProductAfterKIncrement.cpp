#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
const int N=1e9+7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(k--){
            int top=pq.top();
            pq.pop();
            pq.push(top+1);
        }
        long long product=1;
        while(!pq.empty()){
            product=( product*pq.top())%N;
            pq.pop();
        }
        return product;
    }
};