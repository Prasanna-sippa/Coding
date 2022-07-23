#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int f(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i==m-1&&j==n-1){
            return 1;
        }
        if(i>=m ||j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        return dp[i][j]=f(i+1,j,m,n,dp)+f(i,j+1,m,n,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        return f(0,0,m,n,dp);
    }
};


///another

#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i=0;i<m;i++)dp[i][0]=1;
        for(int i=0;i<n;i++)dp[0][i]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
