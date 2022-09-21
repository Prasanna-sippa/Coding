#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int repeat(int n){
    unordered_set<int> s;
    while(n!=0){
        int rem=n%10;
        if(s.find(rem)!=s.end()){
            return 0;
        }
        else{
            s.insert(rem);
            n=n/10;
        }
    }
    return 1;
}
int main()
{
    int l=1,r=100,cnt=0;
    
    for(int i=l;i<=r;i++){
        cnt+=repeat(i);
    }
    cout<<"ans::"<<cnt;
    return 0;
}

