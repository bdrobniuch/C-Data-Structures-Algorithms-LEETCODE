#include <iostream>

using namespace std;

class Node
{
public:
    string key;
    int value;
    Node *next;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

public:
    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            int asciValue = int(key[i]);
            hash = (hash + asciValue * 23) % SIZE;
        }
        return hash;
    }

    void set(string key, int value)
    {
        int index = hash(key);
        Node *newNode = new Node(key, value);

        if (!dataMap[index])
        {
            dataMap[index] = newNode;
        }
        else
        {
            Node *temp = dataMap[index];

            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printTable()
    {
        cout << "Table: " << endl;
        for (int i = 0; i < SIZE; i++)
        {
            cout << "[" << i << "] " << endl;
            Node *n = dataMap[i];
            while (n)
            {
                cout << "   Key: " << n->key << " Value: " << n->value << " " << endl;
                n = n->next;
            }
        }
        cout << endl;
    }
};

int main()
{
    HashTable *newHT = new HashTable();
    newHT->set("pies", 3);
    newHT->set("kot", 4);
    newHT->set("ryba", 5);
    newHT->set("krowa", 19);
    newHT->set("sowa", 3);
    newHT->set("malpa", 4);
    newHT->set("skorpion", 5);
    newHT->set("koczkodan", 19);
    newHT->printTable();
}