Given a binary tree and an integer S, check whether there is root to leaf path with its sum as S.

Example 1:

Input:
Tree = 
            1
          /   \
        2      3
S = 2

Output: 0

class Solution
{
    public:
    bool hasPathSum(Node *root, int S) {
    // Your code here
    if(!root->left && !root->right)
        return (S==root->data);
    if(root->left && hasPathSum(root->left,S-root->data))
        return true;
    if(root->right && hasPathSum(root->right,S-root->data))
        return true;
    return false;
}
};
