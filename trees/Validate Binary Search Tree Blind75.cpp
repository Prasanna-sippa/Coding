class Solution {
    
public:
    bool isValidBST(TreeNode* root) {
       if(root==NULL) return true;
        
        stack<TreeNode*> s;
        TreeNode* pre=NULL;
        while(root!=NULL || !s.empty()){
            while(root!=NULL){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(pre!=NULL && root->val <= pre->val){
                return false;
            } 
            
            pre=root;
            root=root->right;
            
        }
        return true;
    }
};

we have to check if pre is not null and the value is >= root then its failed the bst property

and we can do in brute force way like first find the inorder traversal then check it with sorted form so if both are equal then its bst
