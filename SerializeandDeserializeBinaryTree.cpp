#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
        return "";
        queue<TreeNode *> q;
        q.push(root);
        string data="";
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            if(top==NULL)
                data+="*,";
            else {
                data+=to_string(top->val)+",";
                q.push(top->left);
                q.push(top->right);
            }
        }
        cout<<data;
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="")
        return NULL;

        queue<TreeNode *>q;

        stringstream ss(data);
        string value;
        getline(ss,value,',');
        TreeNode *head=new TreeNode(stoi(value));

        q.push(head);
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            getline(ss,value,',');
            if(value!="*"){
            top->left=new TreeNode(stoi(value));
            q.push(top->left);
            }
            getline(ss,value,',');
            if(value!="*"){
            top->right=new TreeNode(stoi(value));
            q.push(top->right);
            }

        }
        return head;
    }
};