class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        
        int left=0,right=nums.size()-1;
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum<target){
                left++;
            }
            else if(sum>target){
                right--;
            }
            else{
                result.push_back(left+1);
                result.push_back(right+1);
                return result;
            }
            
        }
        return {-1,-1};
    }
};
