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
vector<int> dfs(TreeNode* root, int dis,int &cnt){
    if(root==NULL)
    return {};
    if(root->right ==NULL && root->left==NULL)
    return {1};
    vector<int>left=dfs(root->left,dis,cnt);
    vector<int>right=dfs(root->right,dis,cnt);
    for(auto &x:left){
        for(auto y:right){
            if(x+y<=dis)
            cnt++;
        }
        x=x+1;
    }
    for(auto &y:right){
        left.push_back(y+1);
    }

    return left;
}
    int countPairs(TreeNode* root, int distance) {
        int cnt=0;
        dfs(root,distance,cnt);
        return cnt;
    }
};