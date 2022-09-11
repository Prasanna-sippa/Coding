Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         vector<bool> dp(s.size()+1,false);
        dp[0] = true;
        for(int i=0;i<=s.size();++i){
            for(int j=0;j<i;++j){
                if(dp[j])
                {
                    if(find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))
                                                    != wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                }
                
            }
        }
        return dp[s.size()];
    }
};
