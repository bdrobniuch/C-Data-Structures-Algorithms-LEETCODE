#include <iostream>
#include <vector>

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

    int get(string key) {
        int index = hash(key);
        Node* temp = dataMap[index];

        while (temp) {
            if (key==temp->key) return temp->value;
            temp= temp->next;
        }
        return -1;
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

    vector<string> keys() {
        vector<string> keysStr = {};
        for (Node* nodePtr : dataMap){
            while (nodePtr) {
                keysStr.push_back(nodePtr->key);
                nodePtr= nodePtr->next;
            }
        }
        return keysStr;
    }
    
};

int main()
{
    HashTable *newHT = new HashTable();
    newHT->set("pies", 3);
    newHT->set("kot", 4);
    newHT->set("ryba", 5);
    newHT->set("krowa", 18);
    newHT->set("sowa", 3);
    newHT->set("malpa", 4);
    newHT->set("skorpion", 5);
    newHT->set("koczkodan", 19);
    newHT->printTable();

    cout << "GET krowa " << newHT->get("krowa") << endl;
    cout << "GET lampa " << newHT->get("lampa") << endl;
    cout << "GET koczkodan " << newHT->get("koczkodan") << endl;
    vector<string> keys = newHT->keys();
    for (string s : keys) {
        cout << s  << ", " << endl;
    }
  
}