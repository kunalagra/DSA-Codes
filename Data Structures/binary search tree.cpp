// Binary Search Tree operations in C++

#include <iostream>
using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Inorder Traversal (Using Recursion)
void inorder(struct node *root) {
	if (root != NULL) {
		// Traverse left
		inorder(root->left);
		// Traverse root
		cout << root->data << " ";
		// Traverse right
		inorder(root->right);
	}
}

void preorder(struct node *root) {
	if (root != NULL) {
		// Traverse root
		cout << root->data << " ";
		// Traverse left
		preorder(root->left);
		// Traverse right
		preorder(root->right);
	}
}
void postorder(struct node *root) {
	if (root == NULL) 
	return;
		// Traverse left
		postorder(root->left);
		// Traverse right
		postorder(root->right);
		// Traverse root
		cout << root->data << " ";
	
}

// Insert a node (using Recursion)
struct node *insert(struct node *node, int data) {
	// Return a new node if the tree is empty
	if (node == NULL)
		return newNode(data);
	// Traverse to the right place and insert the node
	if (data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);
	return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
	struct node *current = node;
	// Find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;
	return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int data) {
	// Return if the tree is empty
	struct node *nroot = root;
	if (root == NULL)
		return root;
	// Find the node to be deleted
	if (data < root->data){
		root->left = deleteNode(root->left, data);
	}
	else if (data > root->data){
		root->right = deleteNode(root->right, data);
	}
	else {
	// If the node is with only one child or no child
		if (root->left == NULL) {
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		// If the node has two children
		struct node *temp = minValueNode(root->right);
		// Place the inorder successor in position of the node to be deleted
		root->data = temp->data;
		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->data);

	}

	return root;
}

int main() {
	cout<<"BST in CPP\n";
	struct node *root = NULL;
	int value, exitst=1, choice;
	while(exitst){
		cout<<"\n1. Input\n2. Delete \n3. Display \n4. Exit\nYour Choice: ";
		cin>>choice;
		switch (choice){
			case 1:
				cout<<"Input for insertion: ";
				cin>>value;
				root = insert(root, value);
				break;
			case 2:
				cout<<"Input for delete: ";
				cin>>value;		
				root= deleteNode(root, value);
				break;
			case 3:
				int trav;
				cout<<"\nEnter Traversing Mode: \n";
				cout<<"\n1. Inorder\n2. Preorder\n3. Postorder\n";
				cin>>trav;
				switch (trav){
				case 1:
					inorder(root);
					break;
				case 2:
					preorder(root);
					break;
				case 3:
					postorder(root);
					break;
				default:
					cout<<"Invalid Choice. Try Again";
					break;
				}
				
				break;
			case 4:
				exitst=0;
				break;
			default:
				printf("Invalid choice. Please try Again.");
		}
	}
}