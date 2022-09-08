Given an array arr of n elements which is first increasing and then may be decreasing, find the maximum element in the array.
Note: If the array is increasing then just print then last element will be the maximum value.
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int l=0,h=n-1;
       while(l<=h){
           int mid=l+((h-l)/2);
           if((mid==0 || arr[mid-1]<arr[mid]) && (mid==n-1 || arr[mid+1]<arr[mid])){
               return arr[mid];
           }
           else if(arr[mid-1]<arr[mid]){
               l=mid+1;
           }
           else{
               h=mid-1;
           }
	    }
	return -1;
	}
};


Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)
