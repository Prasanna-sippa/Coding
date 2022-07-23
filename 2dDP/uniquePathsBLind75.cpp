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

/*
    Given grid, return # of unique paths from top-left to bottom-right
    Ex. m = 3, n = 2 -> 3 unique paths (R->D->D, D->D->R, D->R->D)

    DP: edges have 1 unique path, inner cells consider where it comes from
    Recurrence relation: grid[i][j] = grid[i-1][j] + grid[i][j-1]

    Time: O(m x n)
    Space: O(m x n)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            grid[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            grid[0][j] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        
        return grid[m - 1][n - 1];
    }
};


