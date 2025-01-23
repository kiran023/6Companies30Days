#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    int key;
    Node * next=NULL;
    Node *prev=NULL;
    Node(int k,int value){
        key=k;
        val=value;
    }
};
class LRUCache {
    public:
    Node *start=NULL,*end=NULL;
    int cap;
    map<int,Node*>mp;

    private:
    Node* addNewNode(int key,int value){
        Node *t= new Node(key,value);
        if(end!=NULL)
        end->next=t;
        t->prev=end;
        end=t;
        if(start==NULL)
        start=t;
        return t;
    }
    void addToEnd(Node *t){
        if(t==end)
        return;
        if(t->prev!=NULL)
        t->prev->next=t->next;

        t->next->prev=t->prev;
        end->next=t;
        t->prev=end;
        if(t==start)
        start=start->next;

        t->next=NULL;
        end=t;
    }
    void removeLRU(){
        start->next->prev=NULL;
        Node *t=start;
        start=start->next;
        t->next=NULL;
    }

public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        // cout<<start->key<<" "<<end->key<<" ";
        if(mp.find(key)==mp.end())
        return -1;
        addToEnd(mp[key]);
        // cout<<start->key<<" "<<end->key<<" ";
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key]->val=value;
            addToEnd(mp[key]);
            return ;
        }
        Node *t=addNewNode(key,value);
        mp[key]=t;
        if(mp.size()>cap){
            // cout<<start->key<<" "<<end->key;
            mp.erase(start->key);
            removeLRU();
        }   
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */