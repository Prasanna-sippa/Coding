#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
   int candidate=0,count=0;
     for (int i=0;i<n;i++) {
            if (count == 0) {
                candidate = arr[i];
            }
            count += (arr[i] == candidate) ? 1 : -1;
        }
    count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==candidate){
            count++;
        }
    }
    if(count>n/2)return candidate;
    return -1;
    
    return count>n/2 ? candidate: -1;
}
