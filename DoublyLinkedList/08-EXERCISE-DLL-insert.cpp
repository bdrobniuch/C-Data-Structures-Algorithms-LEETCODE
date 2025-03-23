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

            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
        }
        head = newNode;
        length++;
    }

    void deleteFirt()
    {
        if (length == 0)
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
            head = head->next;
            delete (head->prev);
            head->prev = nullptr;
            length--;
        }
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;
        Node *temp;
        if (index < length / 2)
        {
            temp = head;
            for (int i = 0; i < index; i++)
            {
                if (temp)
                    temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for (int i = 0; i < length - index - 1; i++)
            {
                if (temp)
                    temp = temp->prev;
            }
        }

        return temp;
    }

    bool set(int index, int value)
    {

        Node *temp = get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (length == 0 && index == 0)
        {
            Node *newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        } if (index == length) {
            Node *newNode = new Node(value);
            tail->prev->next = newNode;
            newNode->prev= tail->prev;
            tail = newNode;
            length++;
        } else
        {
            Node *temp = get(index);

            if (temp)
            {
                Node *newNode = new Node(value);
                if (index > 0)
                {
                    temp->prev->next = newNode;
                    newNode->prev = temp->prev;
                    temp->prev = newNode;
                }
                newNode->next = temp;
                if (index == 0)
                    head = newNode;
                if (index == length - 1)
                    tail = newNode;
                length++;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    DoublyLinkedList *myDLL = new DoublyLinkedList(1);
    myDLL->append(2);
    myDLL->append(3);
    myDLL->append(4);
    myDLL->append(5);
    myDLL->deleteLast();
    myDLL->prepend(0);
    myDLL->prepend(7);
    myDLL->prepend(7);
    myDLL->deleteFirt();
    myDLL->deleteFirt();

    cout << "Get: " << myDLL->get(1)->value << endl;
    cout << "Get: " << myDLL->get(3)->value << endl;

    myDLL->set(1, 10);
    myDLL->set(3, 30);
    cout << "Get: " << myDLL->get(1)->value << endl;
    cout << "Get: " << myDLL->get(3)->value << endl;

    myDLL->insert(2, 15);
    myDLL->insert(4, 35);
    myDLL->insert(0, 100);
    myDLL->insert(8, 800);
    // cout << "Get: " << myDLL->get(17)->value << endl;

    myDLL->printList();
}