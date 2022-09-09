You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.

You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.
class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isAllocationPossible(int A[], int N, int M,int maxpages){
        
       int stu=1,currpages=0;
        
        for(int i=0;i<N;i++){
            if(A[i]>maxpages)return false;
            if(currpages+A[i]>maxpages){
                stu++;
                if(stu>M)return false;
                currpages=A[i];
            }
            else{
                currpages+=A[i];
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
       int res=INT_MAX,sum=0;
       if(N<M)return -1;
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        int l=A[N-1],h=sum;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isAllocationPossible(A,N,M ,mid)){
                res=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};
