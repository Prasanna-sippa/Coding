Given a string you need to print all possible strings that can be made by placing spaces (zero or one) in between them. The output should be printed in sorted increasing order of strings

Example 1:

Input:
S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)
Explanation:
ABC
AB C
A BC
A B C
These are the possible combination of "ABC".

class Solution{
public:
    void helper(int ind,string s,string cur,vector<string>& res){
        if(ind == s.size()){
            res.push_back(cur);
            return;
        }
        //include
        helper(ind+1,s,cur+" "+s[ind],res);
        
        //exclude
        helper(ind+1,s,cur+s[ind],res);
    }
    vector<string> permutation(string S){
        // Code Here
        vector<string> res;
        string cur;
        cur+=S[0];
        helper(1,S,cur,res);
        return res;
    }
};
