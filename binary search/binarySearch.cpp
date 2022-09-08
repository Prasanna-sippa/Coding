class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K) 
    { 
    
       // Your code here
       int l=0,h=N-1;
       while(l<=h){
           int mid=(l+h)/2;
           if(arr[mid]==K){
               return 1;
           }
           else if(arr[mid]<K){
               l=mid+1;
           }
           else{
               h=mid-1;
           }
       }
       return -1;
       
    }
};
