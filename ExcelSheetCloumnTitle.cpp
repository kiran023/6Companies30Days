#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str="";
        int num=columnNumber;
        while(num!=0){
            num=num-1;
            int rem=num%26;
            num=num/26;
            str.push_back(rem+'A');
        }
        reverse(str.begin(),str.end());
        return str;
    }
};