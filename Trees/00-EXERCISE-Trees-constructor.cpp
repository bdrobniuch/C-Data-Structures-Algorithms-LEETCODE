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

    bool containsBelowNode(Node* node, int value){
        if (!node) return false;
        if (node->value== value) return true;
        if (value < node->value) return containsBelowNode(node->left, value);
        else return containsBelowNode(node->right, value); 
    }

    public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {

            insertAtNode(root, value);

    }

    bool insert2(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return true;
        } 
        Node* temp = root;
        while (true) {
            if (newNode->value == temp->value) return false;
            if (newNode->value < temp->value) 
            {   
                if (!temp->left) {
                    temp->left= newNode;
                    return true;
                }
                    temp=temp->left;
            }
                else {
                    if (!temp->right) {
                        temp->right= newNode;
                        return true;
                    }
                    temp= temp->right;
                }
        }
    }

    void printTree () {
        printNode(root);
    }

    bool contains(int value) {
        
        return containsBelowNode(root, value);
    }

};


int main () {
    BinarySearchTree* newBST =  new BinarySearchTree();
    cout << "Root " << newBST->root << endl;
 //   newBST->insert(4);
 //   newBST->insert(11);
 //   newBST->insert(1);
 //   newBST->insert(19);
 //   newBST->insert(15);
 //   newBST->insert(7);
 newBST->insert2(4);
 newBST->insert2(11);
 newBST->insert2(1);
 newBST->insert2(19);
 newBST->insert2(15);
 newBST->insert2(7);
    newBST->printTree();
    cout << "Cointains 27 " << newBST->contains(27) << endl;
    cout << "Cointains 19 " << newBST->contains(19) << endl;
    cout << "Cointains 1 " << newBST->contains(1) << endl;
}


