#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int s=j+1;
            int e=n-1;
            while(s<=e){
            long long sum=arr[i]+arr[j]+arr[s]+arr[e];
            if(sum==target){
                return "Yes";
            }
            else if(sum<target){
                s++;
            }
            else{
                e--;
            }
         }
      } 
    }
    return "No";
}
