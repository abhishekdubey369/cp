/*
 * Created by: Abhishek Dubey
 * Created on: 2024-04-16
 */
#include <iostream>
#include <bits/stdc++.h>

/**
 * here we will discuss about binary tree
 * have atmost 2 node
 * only 1 root node or node without parents
 * only 1 path from root node to any other node
*/

/**
 * In DFS we start from root node then push right child then left
 * now left node become point of interest
 * if it have child node then continue or else pop and become current node then continue this till leaf node encounter
 * now as leaf node encounters push left leaf node
 * then pop , pop again to n-1 parent node making it as leaf node now same go to left and push its right
 * till step 4
 * then again 5
 * keep repeating until stack becomes empty
*/


using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int k) : data(k), left(nullptr), right(nullptr) {}
};


void inOrder(struct Node* root)
{
    stack<Node*> s;
    Node* curr = root;
 
    while (curr != NULL || s.empty() == false) {
        while (curr != NULL) {

            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
 
        cout << curr->data << " ";
        curr = curr->right;
 
    }
}



int main() {
    // code
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    inOrder(root);
    return 0;
}