#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *right, *left;
};

struct Tree
{
	Node *root = nullptr;
};
void addToTree(Tree *tree, int x) {
	if (!tree->root) {
		tree->root = new Node();
		tree->root->value = x;
	}
	else {
		addToExistingTree(tree->root, x);
	}
}
void addToExistingTree(Node *root, int x) {
	if (root->value > x) {
		if (!root->left) {
			root->left = new Node();
			root->left->value = x;
		}
		else {
			addToExistingTree(root->left, x);
		}
	}
	else {
		if (!root->right) {
			root->right = new Node();
			root->right->value = x;
		}
		else {
			addToExistingTree(root->right, x);
		}
	}
}
int main() {
	Tree tree;
	return 0;
}