
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int i=1,j=0;
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(j=0;j<k;j++){
            pq.push({arr[j],j});
        }
        ans.push_back(pq.top().first);
        
        while(j<arr.size()){
            pq.push({arr[j],j});
            auto top=pq.top();
            while(top.second<i ){
                pq.pop();
            }
            ans.push_back(top.first);
            i++;
            j++;
        }
        return ans;
    }
};

