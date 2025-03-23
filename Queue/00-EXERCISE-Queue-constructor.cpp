#include <iostream>

using namespace std;

class Node
{
public:
    Node *prev;
    Node *next;
    int value;
    Node(int value) {
        this-> value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *last;
    Node *first;
    int length;

public:
    Queue(int value)
    {
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    void printQueue()
    {
        if (!first)
            return;
        Node *current = first;
        while (current)
        {
            cout << current->value << endl;
            current = current->next;
        }
    }
};

int main()
{
    Queue *myQueue = new Queue(7);
    myQueue->printQueue();
}