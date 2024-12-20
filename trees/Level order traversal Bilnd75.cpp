Tree Traversals are 2 types:
1.Breadth First Traversal (Or Level Order Traversal)
2.Depth First Traversals
	a.Inorder Traversal (Left-Root-Right)
	b.Preorder Traversal (Root-Left-Right)
	c.Postorder Traversal (Left-Right-Root)
BFS OR LEVEL ORDER TRAVERSAL:
1.bruteforce Algo: first find the height of the tree and for each level of the tree call a method to traversal, 
in that method check if level is 1 then print the values if level>1 then call the recursive method for eft and right subtrees


Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. 
So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2). 
Auxiliary Space:  O(n) in the worst case. For a skewed tree, printGivenLevel() uses O(n) space for call stack. For a Balanced tree,
the call stack uses O(log n) space, (i.e., the height of the balanced tree). 

2.using queue:
Algorithm: For each node, first, the node is visited and then it’s child nodes are put in a FIFO queue. 

printLevelorder(tree)
1) Create an empty queue q
2) temp_node = root /*start from root*/
3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children 
      (first left then right children) to q
    c) Dequeue a node from q.


Implementation:
/* C++ program to print level
	order traversal using STL */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
	int data;
	struct Node *left, *right;
};

// Iterative method to find height of Binary Tree
void printLevelOrder(Node* root)
{
	// Base Case
	if (root == NULL)
		return;

	// Create an empty queue for level order traversal
	queue<Node*> q;

	// Enqueue Root and initialize height
	q.push(root);

	while (q.empty() == false) {
		// Print front of queue and remove it from queue
		Node* node = q.front();
		cout << node->data << " ";
		q.pop();

		/* Enqueue left child */
		if (node->left != NULL)
			q.push(node->left);

		/*Enqueue right child */
		if (node->right != NULL)
			q.push(node->right);
	}
}

// Utility function to create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	// Let us create binary tree shown in above diagram
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is \n";
	printLevelOrder(root);
	return 0;
}

Level Order traversal of binary tree is 
1 2 3 4 5 
Time Complexity: O(n) where n is the number of nodes in the binary tree.
Auxiliary Space: O(n) where n is the number of nodes in the binary tree.




LEETCODE VARIATION OF LEVEL ORDER:

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrder;
        if(root==NULL) return levelOrder;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while(!queue.empty()){
            vector<int> level;
            int n = queue.size();
            for(int i=0;i<n;i++){
                TreeNode* node = queue.front();
                level.push_back(node->val);
                queue.pop();
                if(node->left){
                    queue.push(node->left);
                }
                if(node->right){
                    queue.push(node->right);
                }
                
            }
            levelOrder.push_back(level);

        }
        return levelOrder;
    }
};
