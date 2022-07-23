class Solution {
private:
    int f(int ind,vector<int>& coins, int amount,vector<vector<int>> &dp){
        if(ind==0) {
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            else{
                return 1e9;
            } 
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int notTake = f(ind-1,coins,amount,dp);
        int take=1e9;
        if(coins[ind]<=amount){
            take=1+f(ind,coins,amount-coins[ind],dp);
        }
        
        return dp[ind][amount]=min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        int ans=f(coins.size()-1,coins,amount,dp);
        if(ans>=1e9)return -1;
        else return ans;
    }
};
