#include<bits/stdc++.h>
using namespace std;
class WordDictionary {
public:
    unordered_set<string>dic;
    unordered_map<int,unordered_set<string>> mp;
    WordDictionary() {
    }
    
    void addWord(string word) {
        dic.insert(word);
        mp[word.size()].insert(word);
    }
    
    bool search(string word) {
        if(dic.count(word))
        return true;
        bool isDot=false;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                isDot=true;
                break;
            }
        }
        if(!isDot)
        return false;

        for(auto x:mp[word.size()]){
            int i=0;
            for(i=0;i<word.size();i++){
                if(word[i]!='.' && word[i]!=x[i])
                 break;
            }
            if(i==word.size())
            return true;

        }
        return false;
    }
};
