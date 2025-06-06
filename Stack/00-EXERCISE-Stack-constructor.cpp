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

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top= newNode;
        height++;
    }

    int pop() {
        if (!top) return INT_MIN;
        Node* oldTop = top;
        int ret = top->value;
        top = top->next;
        delete top;
        return ret;
    }
};

int main() {
    Stack* myStack = new Stack(1);
    myStack->push(2);
    myStack->push(3);
    myStack->push(4);
    myStack->push(5);
    myStack->pop();
    myStack->printStack();
}