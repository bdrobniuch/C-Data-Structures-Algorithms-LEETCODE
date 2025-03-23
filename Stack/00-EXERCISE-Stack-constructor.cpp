#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;
    int height;

public:
    Stack(int value)
    {
        top = new Node(value);
        height = 1;
    }

    Node *getTop() { return top; }

    int getHeight() { return height; }

    void printStack() {
        Node* current = top;
        while (current) {
            cout<<current->value<<endl;
            current = current->next;
        }
    }
};

int main() {
    Stack* myStack = new Stack(1);

    myStack->printStack();
}