Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. 

class Solution{
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& mat,int delrow[],int delcol[]){
        vis[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<4;i++){
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            if(newrow>=0 && newrow<n && newcol>=0 &&newcol<m && !vis[newrow][newcol] && mat[newrow][newcol]=='O'){
                dfs(newrow,newcol,vis,mat,delrow,delcol);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        //first row and last row
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,vis,mat,delrow,delcol);
            }
            
            //last row
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat,delrow,delcol);
            }
        }
        
        //traverse first and last col
        for(int i=0;i<n;i++){
            //first col
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat,delrow,delcol);
            }
            
            //last col
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat,delrow,delcol);
            }
        }
        //remaining 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};
