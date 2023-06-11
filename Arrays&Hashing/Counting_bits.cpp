/*Hey, check out my code
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
6 -- > 110
In this we assume that all i%2 == 0 have the same number of one's in i/3
ex -- 4,2 have the same number of one's
if i==6 i/2 6/2 == 3
number of one's for six and three are equals
i%2 == 1;
we observe that arr[i] = arr[i-1]+1;
for example if i == 5
ans = 2 no. of ones ,
ans[i] = arr[i-1]+1;
4 have only 1 one
1+1=2;
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=1 ; i<=n ; i++){
           if(i%2 == 0){
               ans[i] = ans[i/2];
           }else
               ans[i]=ans[i-1]+1;
            }
            return ans;
    }
};
