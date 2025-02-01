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
int ans=0;
vector<int> isBst(TreeNode *node){
    if(node==NULL)
    return {0,INT_MAX,INT_MIN};
    if(node->left==NULL && node->right==NULL){
        ans=max(ans,node->val);
        return {node->val,node->val,node->val};
    }
    auto left=isBst(node->left);
    auto right=isBst(node->right);
    // cout<<left[2]<<" "<<right[1]<<endl;
    if(left[2]<node->val && right[1]>node->val){
        int currsum=node->val+right[0]+left[0];
        // cout<<currsum;
        ans=max(ans,currsum);
        int mini=left[1];
        int maxi=right[2];
        if(!node->left)
        mini=min(node->val,mini);
        if(!node->right)
        maxi=max(maxi,node->val);

        return {currsum,mini,maxi};
    }
    return {-1,INT_MIN,INT_MAX};
    
}
    int maxSumBST(TreeNode* root) {
        isBst(root);
        return ans;
    }
};