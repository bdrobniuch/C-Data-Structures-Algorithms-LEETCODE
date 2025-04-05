#include <iostream>

using namespace std;

class Node {
    public:
    string key;
    int value;
    Node* next;

    Node(string key, int value)
    {
        this->key = key;
        this->value= value;
        next= nullptr;
    }
};

class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];
    public:

    void printTable() {
        cout<< "Table: ";
        for (int i= 0; i< SIZE; i++)
        {
            cout << "[" << i << "] ";
            Node* n = dataMap[i];
            while (n) {
                cout<< "Key: " << n->key << " Value: " << n->value;
                n= n->next;
            }
        }
        cout<< endl;
    }
};

int main() {
    HashTable* newHT = new HashTable();
    newHT->printTable();
}