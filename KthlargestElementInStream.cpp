#include<bits/stdc++.h>
using namespace std;

class KthLargest {
public:
int kth;
priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k)
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>kth){
            pq.pop();
        }
        return pq.top();
    }
};