class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid;
        int n=nums.size();
        while(left<=right){
            int mid=left+(right-left)/2;
            if((mid==0 || nums[mid]>=nums[mid-1]) && (mid==n-1 || nums[mid]>=nums[mid+1])){
                return mid;
            }
            if(mid>0 && nums[mid]<nums[mid-1]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return mid;
    }
};
