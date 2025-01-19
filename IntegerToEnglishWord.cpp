#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
string findString(string s,unordered_map<int,string>&mp1,unordered_map<int,string>&mp2,unordered_map<int,string>&mp3){
    int n=s.size();
    

    int i=0;
    while(i<n && s[i]=='0'){
        i++;
    }
    if(i==n)
    return "";
    
    s=s.substr(i,s.size()-i);
    n=s.size();

    if(n==1)
    return mp1[stoi(s)];

    if(n==2){
        if(s[0]!='1' && s[1]!='0')
        return mp2[s[0]-'0']+" "+mp1[s[1]-'0'];
        if(s[0]=='1')
        return mp1[stoi(s)];
        return mp2[s[0]-'0'];
    }

    if(n==3){
        string l=findString(s.substr(1,n-1),mp1,mp2,mp3);
        if(l=="")
        return mp1[s[0]-'0']+" "+mp3[n];
        return mp1[s[0]-'0']+" "+mp3[n]+" "+l;
    }

    int subN=((n-1)/3)*3;
    string last=findString(s.substr(n-subN,subN),mp1,mp2,mp3);
    string first=findString(s.substr(0,n-subN),mp1,mp2,mp3);
    if(last=="")
    return first+" "+mp3[n];
    return first+" "+mp3[n]+" "+last;
}
    string numberToWords(int num) {
        if(num==0)
        return "Zero";
        unordered_map<int,string>mp1={{0,"Zero"},{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"},{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"}};

        unordered_map<int,string>mp2={{2,"Twenty"},{3,"Thirty"},{4,"Forty"},{5,"Fifty"},{6,"Sixty"},{7,"Seventy"},{8,"Eighty"},{9,"Ninety"}};

        unordered_map<int,string>mp3={{3,"Hundred"},{4,"Thousand"},{5,"Thousand"},{6,"Thousand"},{7,"Million"},{8,"Million"},{9,"Million"},{10,"Billion"},{11,"Billion"}};

        string s=to_string(num);
        return findString(s,mp1,mp2,mp3);
    }
};