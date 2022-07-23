class Solution {

public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
         for(int i=0;i<=m;i++){
            dp[0][i]=0;
        }
         for(int ind1=1;ind1<=n;ind1++){
             for(int ind2=1;ind2<=m;ind2++){
               
                if(s1[ind1-1]==s2[ind2-1]){
                    dp[ind1][ind2]= 1+dp[ind1-1][ind2-1];
                }
                else
                dp[ind1][ind2]=max(dp[ind1][ind2-1],dp[ind1-1][ind2]);
            }
        }
        return dp[n][m];
    }
};



//neetcode


/*
    Given 2 strings, return length of longest common subsequence
    Ex. text1 = "abcde", text2 = "ace" -> 3, "ace" is LCS

                j
            a   c   e
        a   3
        b       2     --> visualization of below, build DP bottom-up
    i   c       2
        d           1
        e           1

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        
        return dp[0][0];
    }
};


