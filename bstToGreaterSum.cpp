#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class bstToGreaterSum {
private:
    Node* root;

    void bstSumHelper(Node* node, int& sum) {
        if (node == nullptr) {
            return;
        }
        // Traverse right subtree first
        bstSumHelper(node->right, sum);
        
        // Update the current node
        sum += node->data;
        node->data = sum;
        
        // Traverse left subtree
        bstSumHelper(node->left, sum);
    }

    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    bstToGreaterSum() : root(nullptr) {}
    
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

    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    Node* buildBST(int arr[], int size) {
        if (size == 0) {
            return nullptr;
        }
        root = new Node(arr[0]);
        for (int i = 1; i < size; ++i) {
            insert(root, arr[i]);
        }
        return root;
    }

    void bstToGS() {
        int sum = 0;
        bstSumHelper(root, sum);
    }

    ~bstToGreaterSum() {
        deleteTree(root);
    }
};

int main() {
    int arr[] = {4, 1, 6, 0, 2, 3, 5, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    bstToGreaterSum btg;
    Node* root = btg.buildBST(arr, size);
    
    std::cout << "Inorder traversal of the constructed BST: ";
    btg.inorderTraversal(root);
    std::cout << std::endl;

    btg.bstToGS();

    std::cout << "Inorder traversal of the Greater Sum Tree: ";
    btg.inorderTraversal(root);
    std::cout << std::endl;
    
    return 0;
}
