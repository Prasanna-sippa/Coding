/*
    Given int array in a circle, return max amount can rob (can't rob adj houses)
    Ex. nums = [2,3,2] -> 3, can't rob house 1 & 3 b/c circular adj, so rob 2

    Recursion w/ memo -> DP, rob either 2 away + here, or 1 away, try both ranges
    Recurrence relation: robFrom[i] = max(robFrom[i-2] + nums[i], robFrom[i-1])

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) {
            return nums[0];
        }
        
        int range1 = robber(nums, 0, n - 2);
        int range2 = robber(nums, 1, n - 1);
        
        return max(range1, range2);
    }
private:
    int robber(vector<int>& nums, int start, int end) {
        int prev = 0;
        int curr = 0;
        int next = 0;
        
        for (int i = start; i <= end; i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
};









//using dp

class Solution {
    
private:
    int f(vector<int> &nums){
        int prev=nums[0],prev2=0;
        for(int i=1;i<nums.size();i++){
            int pick=nums[i];
                if(i>1){
                    pick+=prev2;
                }
            int nonpick=prev;
            
            int cur=max(nonpick,pick);
            prev2=prev;
            prev =cur;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1){
            return nums[0];
        
        }
        vector<int> a1,a2;
        for(int i=0;i<n;i++){
            if(i!=0){
                a1.push_back(nums[i]);
                
            }
            if(i!=n-1){
                a2.push_back(nums[i]);
            }
        }
        return max(f(a1),f(a2));
    }
};
