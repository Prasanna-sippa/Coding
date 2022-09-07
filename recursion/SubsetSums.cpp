Given a list arr of N integers, print sums of all subsets in it.

 

Example 1:

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.

Expected Time Complexity: O(2^N)
Expected Auxiliary Space: O(2^N)



class Solution
{
public:

    void helper(vector<int>& arr,vector<int>& res,int ind,int n,int cur_sum){
    
    if(ind==n){
        res.push_back(cur_sum);
        return;
    }
    //include
    helper(arr,res,ind+1,n,cur_sum+arr[ind]);
    
    //exclude
    helper(arr,res,ind+1,n,cur_sum);
    
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> res;
        helper(arr,res,0,N,0);
        return res;
    }
    
};
