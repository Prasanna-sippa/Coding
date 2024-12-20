A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 

class Solution 
{
    public:
    bool knows(vector<vector<int> >& M,int A, int B)
{
    return M[A][B];
}

   
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) 
    {
    vector<int> indegree(n), outdegree(n);

      for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(knows(M,i, j)) {
                indegree[j]++;
                outdegree[i]++;
            }
        }
    }

    // Finding Celebrity.
    int celebrity = -1;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == n - 1 && outdegree[i] == 0) {
            celebrity = i;
            break;
        }
    }

    return celebrity;
    }
};
