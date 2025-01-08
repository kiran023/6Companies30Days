#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,bool>vis;
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * t=q.front();
            q.pop();
            vis[t->val]=false;
            if(t->left){
                q.push(t->left);
                adj[t->val].push_back(t->left->val);
                adj[t->left->val].push_back(t->val);
            }
            if(t->right){
                q.push(t->right);
                adj[t->val].push_back(t->right->val);
                adj[t->right->val].push_back(t->val);
            }
        }
        queue<pair<int,int>> pq;
        int time=0;
        pq.push({start,0});
        while(!pq.empty()){
            auto top=pq.front();
            time=max(time,top.second);
            pq.pop();
            vis[top.first]=true;
            for(auto x:adj[top.first]){
                if(!vis[x]){
                    pq.push({x,top.second+1});
                }
            }
        }
        return time;

    }
};