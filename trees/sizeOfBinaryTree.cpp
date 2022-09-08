int getSize(Node* node)
{
   // Your code here
   
    return 1+(node->left ? getSize(node->left) : 0)
            +(node->right ? getSize(node->right) : 0);
   
}
