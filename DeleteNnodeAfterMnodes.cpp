#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node * temp=head;
        while(temp!=NULL){
            int skip=m-1,del=n;
            while(skip && temp!=NULL){
                skip--;
                temp=temp->next;
            }
            if(temp==NULL)
            return head;
            
            Node* p=temp->next;
            
            while(del && p!=NULL){
                del--;
                p=p->next;
            }
            temp->next=p;
            temp=p;
        }
        return head;
    }
};