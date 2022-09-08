Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.

Example 1:

Input:
       1
    /   \
  2      3
 / \    / \
4   5  6   7
Output: 
Explanation:
The tree has 5 vertical lines
Vertical-Line-1 has only one node
4 => vertical sum is 4
Vertical-Line-2: has only one node
2=> vertical sum is 2
Vertical-Line-3: has three nodes:
1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3
=> vertical sum is 3
Vertical-Line-5: has only one node 7
=> vertical sum is 7

class Solution{
    map<int,int> mp;
    
  public:
    void helper(Node *root,int dist){
        mp[dist]+=root->data;
        
        if(root->left)
            helper(root->left,dist-1);
        if(root->right)
            helper(root->right,dist+1);
    }
    vector <int> verticalSum(Node *root) {
        // add code here.
        
        helper(root,0);
        vector<int> res;
        for(auto c: mp){
            res.push_back(c.second);
        }
        return res;
    }
};
