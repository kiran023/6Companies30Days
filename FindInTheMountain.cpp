#include<bits/stdc++.h>
using namespace std;

  class MountainArray {
    public:
      int get(int index);
      int length();
  };

class Solution {
public:
int bs1(int i,int j,int target,MountainArray &mountainArr,unordered_map<int,int> &mp){
    while(i<=j){
        int mid=(i+j)/2;
        int midVal;

        if(mp.count(mid))
        midVal =mp[mid];
        else{
            midVal=mountainArr.get(mid);
            mp[mid]=midVal;
        } 

        if(midVal==target)
        return mid;
        if(midVal>target)
        j=mid-1;
        else i=mid+1;
    }
    return -1;
}
int bs2(int i,int j,int target,MountainArray &mountainArr,unordered_map<int,int> &mp){
    while(i<=j){
        int mid=(i+j)/2;
        int midVal;
        if(mp.count(mid))
        midVal=mp[mid];
        else {
            midVal=mountainArr.get(mid);
            mp[mid]=midVal;
        }
        if(mountainArr.get(mid)==target)
        return mid;
        if(mountainArr.get(mid)>target)
        i=mid+1;
        else j=mid-1;
    }
    return -1;
}
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        unordered_map<int,int> mp;
        int i=1,j=n-2;
        int ind;
        while(i<=j){
            int mid=(i+j)/2;
            int midVal=mountainArr.get(mid);
            int midMore=mountainArr.get(mid+1);
            int midLess=mountainArr.get(mid-1);
            mp[mid]=midVal;
            mp[mid+1]=midMore;
            mp[mid-1]=midLess;

            if(midVal>midMore && midVal>midLess)
            {
                ind=mid;
                break;
            }
            else if(midVal<midLess)
            j=mid-1;
            else i=mid+1;
        }
        int left=bs1(0,ind,target,mountainArr,mp);
        int right=bs2(ind+1,n-1,target,mountainArr,mp);
        if(left==-1 )
        return right;
        return left;

    }
};