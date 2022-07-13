Algorithm 
1. Starting at the root, find the deepest and rightmost node in the binary tree and the node which we want to delete. 
2. Replace the deepest rightmost node’s data with the node to be deleted. 
3. Then delete the deepest rightmost node.



// C++ program to delete element in binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node {
	int key;
	struct Node *left, *right;
};

/* function to create a new node of tree and
return pointer */
struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};

/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}

/* function to delete the given deepest node
(d_node) in binary tree */
void deletDeepest(struct Node* root,
				struct Node* d_node)
{
	queue<struct Node*> q;
	q.push(root);

	// Do level order traversal until last node
	struct Node* temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == d_node) {
			temp = NULL;
			delete (d_node);
			return;
		}
		if (temp->right) {
			if (temp->right == d_node) {
				temp->right = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->right);
		}

		if (temp->left) {
			if (temp->left == d_node) {
				temp->left = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->left);
		}
	}
}

/* function to delete element in binary tree */
Node* deletion(struct Node* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL) {
		if (root->key == key)
			return NULL;
		else
			return root;
	}

	queue<struct Node*> q;
	q.push(root);

	struct Node* temp;
	struct Node* key_node = NULL;

	// Do level order traversal to find deepest
	// node(temp) and node to be deleted (key_node)
	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->key == key)
			key_node = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}

	if (key_node != NULL) {
		int x = temp->key;
		deletDeepest(root, temp);
		key_node->key = x;
	}
	return root;
}

// Driver code
int main()
{
	struct Node* root = newNode(10);
	root->left = newNode(11);
	root->left->left = newNode(7);
	root->left->right = newNode(12);
	root->right = newNode(9);
	root->right->left = newNode(15);
	root->right->right = newNode(8);

	cout << "Inorder traversal before deletion : ";
	inorder(root);

	int key = 11;
	root = deletion(root, key);

	cout << endl;
	cout << "Inorder traversal after deletion : ";
	inorder(root);

	return 0;
}
Time complexity: O(n) where n is no number of nodes

Auxiliary Space: O(n) size of queue

Note: We can also replace the node’s data that is to be deleted with any node whose left and right child points to NULL but we only use deepest node in order to maintain the Balance of a binary tree.

Important Note: The above code will not work if the node to be deleted is the deepest node itself because after the function deletDeepest(root, temp) completes execution, the key_node gets deleted(as here key_node is equal to temp)and after which replacing key_node‘s data with the deepest node’s data(temp‘s data) throws a runtime error.
