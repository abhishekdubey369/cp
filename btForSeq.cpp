/*
 * Created by: Abhishek Dubey
 * Created on: 2024-05-22
 */
#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x):data(x),left(nullptr),right(nullptr){};
};

Node* insert(Node* node, int data) {
    if (node == nullptr) {
        return new Node(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

Node* buildBST(int arr[], int size) {
    if (size == 0) {
        return nullptr;
    }
    Node* root = new Node(arr[0]);
    for (int i = 1; i < size; ++i) {
        insert(root, arr[i]);
    }
    return root;
}

void inorderTraversal(Node* node) {
    if (node != nullptr) {
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }
}

int main() {
    /* code */

    int arr[] = {50, 70, 60, 20, 90, 10, 40, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBST(arr, size);
    std::cout << "Inorder traversal of the constructed BST: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}