/*
 * Created by: Abhishek Dubey
 * Created on: 2024-05-21
 */
#include <iostream>

using namespace std;


//definig node 

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int x):data(x),left(nullptr),right(nullptr){};
};


class allLeavesAtSameLevel
{
private:
    Node* root;
    bool checkLeavesLevel(Node* node, int level, int& leafLevel) {
        if (node == nullptr)
            return true;
        if (node->left == nullptr && node->right == nullptr) {
            if (leafLevel == -1)
                leafLevel = level;
            else {
                if (level != leafLevel)
                    return false;
            }
            return true;
        }
        return checkLeavesLevel(node->left, level + 1, leafLevel) &&
               checkLeavesLevel(node->right, level + 1, leafLevel);
    }
public:
    allLeavesAtSameLevel(Node* tree):root(tree){};
    bool areLeavesAtSameLevel();
    ~allLeavesAtSameLevel();
    void deleteTree(Node* node);
};

bool allLeavesAtSameLevel::areLeavesAtSameLevel(){

    if(root == nullptr)
        return true;
    
    int leafLevel = -1;

    return checkLeavesLevel(root,0,leafLevel);
}

void allLeavesAtSameLevel::deleteTree(Node* node){
    if (node == nullptr)
        return;
    
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

allLeavesAtSameLevel::~allLeavesAtSameLevel()
{
    deleteTree(root);
}


int main() {
    /* code */
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    allLeavesAtSameLevel ans(root);

    cout<<ans.areLeavesAtSameLevel()<<endl;

    return 0;
}