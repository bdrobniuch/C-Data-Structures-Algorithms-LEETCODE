#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
    vector<int> heap;

    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        if (heap.size() == 1)
            return;

        int childIndex = heap.size() - 1;
        int parentIndex = 0;
        while (childIndex != 0)
        {

            parentIndex = parent(childIndex);

            if (heap[parentIndex] < heap[childIndex])
                swap(parentIndex, childIndex);

            childIndex = parentIndex;
        }
    }

    void print()
    {
        for (auto i : heap)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
};

int main()
{
    Heap heap;
    heap.insert(4);
    heap.insert(2);
    heap.insert(5);
    heap.insert(1);
    heap.insert(7);
    heap.insert(1);
    heap.insert(9);

    heap.print();
}