


Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.


Example 1:

Input:
N = 3
Output:
((()))
(()())
(())()
()(())
()()()


class Solution
{
    public:
    void helper(string cur,int o,int c,int n,vector<string>& res){
        if(c==o && c==n){
            res.push_back(cur);
            return;
        }
        //open
        if(o<n){
            helper(cur+"(",o+1,c,n,res);
            
        }
        //close
         if(o>c){
            helper(cur+")",o,c+1,n,res);
            
        }
        
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> res;
        
        helper("",0,0,n,res);
        return res;
        
    }
};



Expected Time Complexity: O(2N * N).
Expected Auxiliary Space: O(2*N*X), X = Number of valid Parenthesis.
