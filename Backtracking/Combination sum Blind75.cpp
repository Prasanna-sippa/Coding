Intuition:

For questions like printing combinations or subsequences, the first thing that should strike your mind is recursion.

How to think recursively?

Whenever the problem is related to picking up elements from an array to form a combination, start thinking about the “pick and non-pick” approach.


Initially, the index will be 0, target as given and the data structure(vector or list) will be empty

Now there are 2 options viz to pick or not pick the current index element.

If you pick the element, again come back at the same index as multiple occurrences of the same element is possible so the target reduces to target – arr[index] (where target -arr[index]>=0)and also insert the current element into the data structure.

If you decide not to pick the current element, move on to the next index and the target value stays as it is. Also, the current element is not inserted into the data structure.

While backtracking makes sure to pop the last element as shown in the recursion tree below.

Keep on repeating this process while index < size of the array for a particular recursion call.

You can also stop the recursion when the target value is 0, but here a generalized version without adding too many conditions is considered.

Using this approach, we can get all the combinations.

Base condition

If index== size of array and  target == 0 include the combination in our answer



class Solution {
public:
    void findCombination(int index,vector<int>& candidates, int target,vector<int>& ds,vector<vector<int>> &ans){
        if(index==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        
        //pick element
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            findCombination(index,candidates,target-candidates[index],ds,ans);
            ds.pop_back();
        }
        //not pick
        findCombination(index+1,candidates,target,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,candidates,target,ds,ans);
        
        return ans;
    }
};



Time Complexity: O(2^t * k) where t is the target, k is the average length

Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

Why not (2^n) but (2^t) (where n is the size of an array)?

Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

Space Complexity: O(k*x), k is the average length and x is the no. of combinations
