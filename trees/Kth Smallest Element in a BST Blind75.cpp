1.with inorder recursion :

class Solution {
public:
    void helper(TreeNode*root,vector<int >&v){
        if(root==nullptr)return ;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        helper(root,v);
        return v[k-1];
    }
        
};

2.with inorder recursion but returning early rather than waiting till end:

class Solution {
public:
    
    void inorder(TreeNode* root,int &k,int &ans){
        if(!root)return;
        
        inorder(root->left,k,ans);
        if(--k==0){
            ans=root->val;
            return;
        }
        inorder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root,k,ans);
        return ans;
    }
};
