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

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {
        head = new Node(value);
        tail = head;
        length = 1;
    }

    ~LinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead()
    {
        if (head == nullptr)
        {
            cout << "Head: nullptr" << endl;
        }
        else
        {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail()
    {
        if (tail == nullptr)
        {
            cout << "Tail: nullptr" << endl;
        }
        else
        {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            tail = newNode;
            head = newNode;
        } else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    { //A->B->C->D
        if (length > 1) 
        {
            Node* i = head;
            while (i->next->next != nullptr) {
                i = i->next;
            }
            delete tail;
            tail = i;
            length--;
            i->next = nullptr;
            
        } else if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = 0;

        }
    }
};

int main()
{

    LinkedList *myLinkedList = new LinkedList(1);


    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->deleteLast();
    myLinkedList->deleteLast();
    myLinkedList->deleteLast();
    myLinkedList->deleteLast();
    myLinkedList->deleteLast();

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    cout << "\nLinked List:\n";
    myLinkedList->printList();

    /*
        EXPECTED OUTPUT:
        ----------------
        Head: 4
        Tail: 4
        Length: 1

        Linked List:
        4

    */
}
