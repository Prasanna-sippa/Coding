Given a set of positive integers, find all its subsets.

Example 1 :

Input : 
array = {1, 2, 3}
Output :
// this space denotes null element. 
1
1 2
1 2 3
1 3
2
2 3
3
Explanation: 
The following are the subsets 
of the array {1, 2, 3}.

class Solution
{
    public:
    void helper(vector<int>& A,int ind,  vector<vector<int>>& res, vector<int> &cur){
        if(ind==A.size()){
            res.push_back(cur);
            return;
        }
        
        //include
        cur.push_back(A[ind]);
        helper(A,ind+1,res,cur);
        cur.pop_back();
        
        //exclude
        helper(A,ind+1,res,cur);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>> res;
        vector<int> cur;
        helper(A,0,res,cur);
        sort(res.begin(),res.end());
        return res;
    }
};
