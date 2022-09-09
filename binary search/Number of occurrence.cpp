//array is sorted
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
    int findHelper(int arr[], int N , int K,bool isFirst){
    int l=0,h=N-1,ans=-1;
    int first=-1,last=-1;
       while(l<=h){
           int mid=l+((h-l)/2);
           if(arr[mid]==K){
               if(isFirst){
                   h=mid-1;
               }
               else{
                   l=mid+1;
               }
               ans=mid;
           }
           else if(arr[mid]<K){
               l=mid+1;
           }
           else{
               h=mid-1;
               
           }
       }
       return ans;
       
}
	int count(int arr[], int N, int K) {
	    int l=0,h=N-1;
    int first=-1,last=-1;
     first=findHelper(arr,N,K,true);
     last=findHelper(arr,N,K,false);
     
     return first<0?0:last-first+1;
	}
};
