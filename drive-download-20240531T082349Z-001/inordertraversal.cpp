#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

class BinaryTree
{
private:
    Node* root;
public:
    BinaryTree():root(nullptr){};
    int search(int arr[], int strt, int end, int value);
    int* extrackKeys(int in[], int level[], int m, int n);
    Node* buildTree(int in[], int level[], int inStrt,int inEnd, int n);
    Node* newNode(int key);
    ~BinaryTree();
};


BinaryTree::~BinaryTree()
{
    delete root;
}


int BinaryTree::search(int arr[], int strt, int end, int value)
{
	for (int i = strt; i <= end; i++)
		if (arr[i] == value)
			return i;
	return -1;
}


int* BinaryTree::extrackKeys(int in[], int level[], int m, int n)
{
	int *newlevel = new int[m], j = 0;
	for (int i = 0; i < n; i++)
		if (search(in, 0, m - 1, level[i]) != -1)
			newlevel[j] = level[i], j++;
	return newlevel;
}

Node* BinaryTree::newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}


Node* BinaryTree::buildTree(int in[], int level[], int inStrt,
				int inEnd, int n)
{
	if (inStrt > inEnd)
		return NULL;

	Node* root = newNode(level[0]);

	if (inStrt == inEnd)
		return root;
	int inIndex = search(in, inStrt, inEnd, root->key);
	int* llevel = extrackKeys(in, level, inIndex, n);
	int* rlevel= extrackKeys(in + inIndex + 1, level, n - 1, n);
	root->left = buildTree(in, llevel, inStrt, inIndex - 1,inIndex - inStrt);
	root->right = buildTree(in, rlevel, inIndex + 1, inEnd,inEnd - inIndex);
	delete[] llevel;
	delete[] rlevel;

	return root;
}

void printInorder(Node* node)
{
	if (node == NULL)
		return;
	printInorder(node->left);
	cout << node->key << " ";
	printInorder(node->right);
}

int main()
{
	int in[] = {  3, 4, 2, 1, 5, 8, 9 };
	int level[] = { 1, 4, 5, 9, 8, 2, 3 };
	int n = sizeof(in) / sizeof(in[0]);
    BinaryTree bt;
	Node* root = bt.buildTree(in, level, 0, n - 1, n);

	cout << "Inorder traversal of the constructed tree is "
			"\n";
	printInorder(root);

	return 0;
}
