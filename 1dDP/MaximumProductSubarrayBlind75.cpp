class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int max = INT_MIN, product = 1;
        int len = nums.size();
         for(int i = 0; i < len; i++) {
             product *= nums[i];
             max = std::max(product, max);
             if (nums[i] == 0) product = 1;
         }

         product = 1;
         for(int i = len - 1; i >= 0; i--) {
             product *= nums[i];
             max = std::max(product, max);
             if (nums[i] == 0) product = 1;
         }

     return max;
    }
    
};
