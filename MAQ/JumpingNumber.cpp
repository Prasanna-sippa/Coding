Given a positive number X. Find the largest Jumping Number smaller than or equal to X. 
Jumping Number: A number is called Jumping Number if all adjacent digits in it differ by only 1. All single digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796 and 89098 are not.

 

Example 1:

Input:
X = 10
Output:
10
Explanation:
10 is the largest Jumping Number
possible for X = 10.

class Solution {
  public:
  void bfs(long long x,int num,vector<long long>& res){
      queue<long long> q;
      q.push(num);
      while(!q.empty()){
          num=q.front();
          q.pop();
          
          if(num<=x){
              res.push_back(num);
              int last_dig=num%10;
              
              if(last_dig==0){
                  
                  q.push((num*10)+(last_dig+1));
              }
              else if(last_dig==9){
                  q.push((num*10)+(last_dig-1));
              }
              else{
                  q.push((num*10)+(last_dig+1));
                  q.push((num*10)+(last_dig-1));
              }
          }
      }
    
  }
    long long jumpingNums(long long X) {
        // code here
        vector<long long> res;
        for (int i = 1; i <= 9 && i <= X; i++){
         bfs(X, i,res);
        }
        return *max_element(res.begin(),res.end());
    }
};
