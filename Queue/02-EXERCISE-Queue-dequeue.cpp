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

    void enqueue(int value)
    {
        Node* newNode = new Node(value);
        last->next = newNode;
        last=  newNode;
        if (length==0) first= newNode;
        length++;
    }

    int dequeue() 
    {
        if (!first) return INT_MIN;
        Node* temp = first;
        int tempInt = first->value;
        first= first->next;
        delete (temp);
        length--;
        return tempInt;
    }
};

int main()
{
    Queue *myQueue = new Queue(7);
    myQueue->enqueue(2);
    myQueue->enqueue(3);
    myQueue->enqueue(4);
    cout << "D " << myQueue->dequeue() << endl;
    cout << "D " << myQueue->dequeue() << endl;
    myQueue->printQueue();
}