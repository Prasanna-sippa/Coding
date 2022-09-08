int getSize(Node* node)
{
   // Your code here
   
    return 1+(node->left ? getSize(node->left) : 0)
            +(node->right ? getSize(node->right) : 0);
   
}


//height of tree
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        
        return 1+max((node->left ? height(node->left) : 0),
                 (node->right ? height(node->right):0));
    }
};
