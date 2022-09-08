Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

 

Example 1:

Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect 
square, floor of square_root of 5 is 2.
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        if(x==1)return 1;
        long long l=1,h=x/2;
        long long ans;
        while(l<=h){
            long long mid=l+(h-l)/2;
            long long sqrt=mid*mid;
            if(sqrt>x){
                h=mid-1;
            }
            else if(sqrt<x){
                ans=mid;
                l=mid+1;
            }
            else{
                return mid;
            }
        }
        return ans;
    }
};
