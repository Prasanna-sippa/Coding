1.using 2 methods

vector<int> find(int arr[], int N , int K)
{
    // first pos
    int l=0,h=N-1;
    int first=-1,last=-1;
       while(l<=h){
           int mid=l+((h-l)/2);
           if(arr[mid]==K){
               first=mid;
               h=mid-1;
           }
           else if(arr[mid]<K){
               l=mid+1;
           }
           else{
               h=mid-1;
               
           }
       }
       
       //last pos
       l=0,h=N-1;
        while(l<=h){
           int mid=l+((h-l)/2);
           if(arr[mid]==K){
               last=mid;
               l=mid+1;
           }
           else if(arr[mid]<K){
               l=mid+1;
           }
           else{
               h=mid-1;
               
           }
       }
    //   vector<int> res;
    //   res.push_back(first);
    //   res.push_back(last);
    //   return res;
    return {first,last};
}
we have to reduce redundanacy as both methods have same code except one line

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
vector<int> find(int arr[], int N , int K)
{
    // first pos
    int l=0,h=N-1;
    int first=-1,last=-1;
     first=findHelper(arr,N,K,true);
     last=findHelper(arr,N,K,false);
    //   vector<int> res;
    //   res.push_back(first);
    //   res.push_back(last);
    //   return res;
    return {first,last};
}
