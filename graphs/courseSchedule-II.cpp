There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0.


Example 1:

Input:
n = 2, m = 1
prerequisites = {{1, 0}}
Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible order is [0, 1].\








class Solution
{
  public:
    vector<int> findOrder(int numCourses, int m, vector<vector<int>> prerequisites) 
    {
        //code here
         vector<int> adj[numCourses];
        for(auto it :prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        
        if(topo.size()==numCourses) return topo;
        return {};
    }
};
