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



peak means: if a element is greater than its left and right element than its a peak so return if its the mid else check other conditions below
logic is if left of mid is greater than mid than definetly the ans will lie in left side,
and if the right of mid greater than mid than ans lies in right side based on that we have to change 
the mid value and we have to check the edge cases like what if mid is 0 and what if mid is last element so we ahve to return in these cases
