class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dis=0,n=nums.size();
        for(int i=0;i<=dis;i++){
            dis=max(dis,nums[i]+i);
            if(dis>=n-1){
                return true;
            }
        }
        return false;
    }
    
};

 
