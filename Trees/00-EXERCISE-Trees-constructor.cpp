#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* left;
    Node* right;

    
    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
    private:
    void insertAtNode(Node* &node, int value) {
        if (!node) node = new Node(value); 
        else if (node->value == value) return;
        else if (node->value > value) {
            insertAtNode(node->left, value);
        } else {
            insertAtNode(node->right, value);
        }
    }

    void printNode(Node* node) {
        if (node->left) printNode(node->left);
        cout << "Node " << node->value << endl;
        if (node->right) printNode(node->right);
    }

    public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {

            insertAtNode(root, value);

    }

    void printTree () {
        printNode(root);
    }

};


int main () {
    BinarySearchTree* newBST =  new BinarySearchTree();
    cout << "Root " << newBST->root << endl;
    newBST->insert(4);
    newBST->insert(11);
    newBST->insert(1);
    newBST->insert(19);
    newBST->insert(15);
    newBST->insert(7);
    newBST->printTree();
}


