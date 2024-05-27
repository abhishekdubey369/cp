/*
 * Created by: Abhishek Dubey
 * Created on: 2024-05-24
 */
#include <iostream>
#include <vector>
using namespace std;

class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;
    
    AVLNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLNode* insert(AVLNode* root, int key) {
        if (!root) return new AVLNode(key);
        if (key < root->key)
            root->left = insert(root->left, key);
        else if (key > root->key)
            root->right = insert(root->right, key);
        else 
            return root;
        
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);
        
        if (balance > 1 && key < root->left->key)
            return rightRotate(root);
        if (balance < -1 && key > root->right->key)
            return leftRotate(root);
        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
    }

    AVLNode* deleteNode(AVLNode* root, int key) {
        if (!root) return root;
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left || !root->right) {
                AVLNode* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else
                    *root = *temp;
                delete temp;
            } else {
                AVLNode* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (!root) return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);
        
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        
        return root;
    }

    void preOrder(AVLNode* root) {
        if (root) {
            cout << root->key << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void minNodes(AVLNode* root){
        int height = getHeight(root);
        if (height == 0) cout<< 1<<endl;
        if (height == 1) cout<<2<<endl;
        vector<int> dp(height +1);
        dp[0]=1;
        dp[1]=2;
        for (int i = 2; i <= height; ++i) {
            dp[i] = 1 + dp[i - 1] + dp[i - 2];
            }
        
        cout<<dp[height]<<endl;
        
    }

private:
    int getHeight(AVLNode* root) {
        return root ? root->height : 0;
    }

    int getBalance(AVLNode* root) {
        return root ? getHeight(root->left) - getHeight(root->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }
};
int main() {
    AVLTree tree;
    AVLNode* root = nullptr;
    int keys[] = {10, 20, 30, 40, 50, 25};

    for (int key : keys)
        root = tree.insert(root, key);

    cout << "Preorder traversal of the constructed AVL tree is:\n";
    tree.preOrder(root);
    cout << endl;

    root = tree.deleteNode(root, 40);
    cout << "Preorder traversal after deletion of 40:\n";
    tree.preOrder(root);
    cout << endl;
    tree.minNodes(root);

    return 0;
}
