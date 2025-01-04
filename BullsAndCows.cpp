#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int>mp;
        int bull=0;
        int cow=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                guess[i]='#';
                bull++;
            }
            else mp[secret[i]]++;
        }
        for(int i=0;i<guess.size();i++){
            if(guess[i]=='#')
            continue;
            if(mp.find(guess[i])!=mp.end()){
                mp[guess[i]]--;
                cow++;
                if(mp[guess[i]]==0)
                mp.erase(guess[i]);
            }
        }
        return to_string(bull)+'A'+to_string(cow)+'B';
    }
};