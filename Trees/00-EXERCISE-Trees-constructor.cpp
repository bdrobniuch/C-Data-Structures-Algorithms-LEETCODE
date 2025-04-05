#include <iostream>

using namespace std;

class Node {
    int value;
    Node* left;
    Node* right;

    public:
    Node(int value) {
        this->value = value;
    }
}