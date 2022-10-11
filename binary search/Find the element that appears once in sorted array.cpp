class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        if(arr[0]!=arr[1]){
            return arr[0];
        }
        if(arr[n-1]!=arr[n-2]){
            return arr[n-1];
        }
        
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]){
                return arr[mid];
            }
            else if(arr[mid]==arr[mid+1] && mid%2==0 || arr[mid]==arr[mid-1] && mid%2!=0){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};


tc:o(logn)
