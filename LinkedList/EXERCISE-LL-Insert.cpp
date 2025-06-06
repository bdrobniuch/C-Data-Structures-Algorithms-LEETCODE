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
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    { // A->B->C->D
        if (length > 1)
        {
            Node *i = head;
            while (i->next->next != nullptr)
            {
                i = i->next;
            }
            delete tail;
            tail = i;
            length--;
            i->next = nullptr;
        }
        else if (length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = 0;
        }
    }

    void prepend(int value)
    {
        Node *temp = new Node(value);
        if (length == 0)
        {
            head = temp;
            tail = temp;
            length = 1;
        }
        else
        {
            temp->next = head;
            head = temp;
            length++;
        }
    }

    void deleteFirst()
    {
        if (length > 0)
        {
            Node *temp;
            temp = head;
            head = temp->next;
            delete (temp);
            if (!head)
            {
                tail = head;
            }
            length--;
        }
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
        {
            return nullptr;
        }

        int i = index;
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value)
    {
        Node* temp = get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
        {
            return false;
        }
        // A B C

        if (index == 0)
        {
            
            prepend(value);
            return true;
        } else if (index == length) {
            append(value);
            return true;
        } else {
            
            Node* prev = get(index-1);
            if (prev) {
                Node* temp = new Node(value);
                temp->next = prev->next;
                prev->next = temp;
                length++;
                return true;
            }
        }

 

        return false;
        
    }
};

int main()
{

    LinkedList *myLinkedList = new LinkedList(1);

    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->append(6);
    myLinkedList->append(7);
    myLinkedList->deleteLast();
    myLinkedList->prepend(0);
    myLinkedList->deleteFirst();
    myLinkedList->deleteFirst();





    myLinkedList->set(1, 10);

    myLinkedList->set(2, 20);

    myLinkedList->set(3, 30);

    myLinkedList->set(-2, 20);

    cout << "Get: " << 1 << "-" << myLinkedList->get(1)->value << endl;

    cout << "Get: " << 2 << "-" << myLinkedList->get(2)->value << endl;

    myLinkedList->insert(3,25);
    myLinkedList->insert(6,65);
    myLinkedList->insert(8,8);

    cout << "\nLinked List:\n";
    myLinkedList->printList();

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

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
