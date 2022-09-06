Given a string S. The task is to find all permutations of a given string.

Example 1:

Input:
S = ABC
Output: ABC ACB BAC BCA CAB CBA 

class Solution{
    public:
    //Complete this function
    
    void helper(string s,int ind,vector<string>& res){
        if(ind == s.size()){
            res.push_back(s);
            return;
        }
        
        for(int i=ind;i<s.size();i++){
            swap(s[i],s[ind]);
            helper(s,ind+1,res);
            swap(s[ind],s[i]);
        }
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string> res;
        helper(S,0,res);
        sort(res.begin(),res.end());
        return res;
    }
};
