Given a string S, Find all the possible subsequences of the String in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 subsequences that 
can be formed from abc.
  
class Solution{
	public:
	void helper(string s,int ind,int n,string cur,vector<string>& res){
	    if(ind==n){
	        res.push_back(cur);
	        return;
	    }
	    
	    //include
	    helper(s,ind+1,n,cur+s[ind],res);
	    //exclude
	    helper(s,ind+1,n,cur,res);
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> res;
		    helper(s,0,s.size(),"",res);
		    sort(res.begin(),res.end());
		    res.erase(res.begin());
		    return res;
		}
};
