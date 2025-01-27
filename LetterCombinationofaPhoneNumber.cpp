#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char,string>mp={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };
    vector<string>ans;
void f(int i,string &s,string &digit){
    if(i==digit.size()){
        ans.push_back(s);
        return;
    }
    string curr=mp[digit[i]];
    for(int j=0;j<curr.size();j++){
        s.push_back(curr[j]);
        f(i+1,s,digit);
        s.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        return {};
        string s;
        f(0,s,digits);
        return ans;
    }
};