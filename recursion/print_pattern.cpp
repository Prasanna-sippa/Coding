Print a sequence of numbers starting with N where A[0] = N, without using loop, in which  A[i+1] = A[i] - 5,  until A[i] > 0. After that A[i+1] = A[i] + 5  repeat it until A[i] = N.

Example 1:

Input: N = 16
Output: 16 11 6 1 -4 1 6 11 16
Explaination: The value decreases until it 
is greater than 0. After that it increases 
and stops when it becomes 16 again.


class Solution{
public:
    void helper(int N,vector<int> &res){
        if(N<=0){
            res.push_back(N);
            return ;
            
        }
        res.push_back(N);
        helper(N-5,res);
        res.push_back(N);
        
        
    }
    vector<int> pattern(int N){
        // code here
        vector<int> res;
        helper(N,res);
        return res;
    }
};
