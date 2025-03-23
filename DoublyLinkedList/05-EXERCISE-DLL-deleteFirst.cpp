#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value)
    {
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        head = new Node(value);
        tail = head;
        length = 1;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void getHead()
    {
        cout << "Head: " << head->value << endl;
    }

    void getTail()
    {
        cout << "Tail: " << tail->value << endl;
    }

    void getLength()
    {
        cout << "Head: " << length << endl;
    }

    void append(int value)
    {

        Node *newNode = new Node(value);

        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (!length)
            return;
        if (length == 1)
        {
            delete (head);
            head = nullptr;
            tail = nullptr;
            length = 0;
        }
        else
        {
            tail = tail->prev;
            delete (tail->next);
            tail->next = nullptr;
            length--;
        }
    }

    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {

            tail= newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            
        }
        head = newNode;
        length++;
    }

    void deleteFirt() {
        if (length==0) return;
        if (length==1) {
            delete(head);
            head = nullptr;
            tail = nullptr;
            length = 0;
        } else {
            head = head->next;
            delete(head->prev);
            head->prev= nullptr;
            length--;
        }

    }
};

int main()
{
    DoublyLinkedList *myDLL = new DoublyLinkedList(1);
    myDLL->append(2);
    myDLL->append(3);
    myDLL->append(4);
    myDLL->deleteLast();
    myDLL->prepend(0);
    myDLL->prepend(7);
    myDLL->prepend(7);
    myDLL->deleteFirt();
    myDLL->deleteFirt();
    myDLL->printList();
}