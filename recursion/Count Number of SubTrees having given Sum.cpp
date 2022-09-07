
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
Example: For the tree given below:            

              5
            /    \
        -10       3
        /    \    /  \
      9       8  -4     7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).


int helper(Node* root,int X,int& cnt){
    
    int sum=0,lsum=0,rsum=0;
    
    if(root->left){
         lsum=helper(root->left,X,cnt);
    }
    if(root->right){
      rsum=helper(root->right,X,cnt);
    }
    
    sum=lsum+rsum+root->data;
    
    if(sum==X){
        cnt++;
    }
    return sum;
}
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int cnt=0;
	helper(root,X,cnt);
	return cnt;
}
