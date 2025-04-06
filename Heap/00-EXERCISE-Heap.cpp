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

        while (childIndex != 0 && heap[parent(childIndex)] < heap[childIndex])
        {

            swap(parent(childIndex), childIndex);
            childIndex = parent(childIndex);
        }
    }

    int remove()
    {
        if (heap.empty())
            return INT_MIN;
        int maxValue = heap.front();

        if (heap.size() == 1)
            heap.pop_back();
        else
        {
            heap[0]= heap.back();
            heap.pop_back();
        }

        return maxValue;
    }

    void sinkDown(int index) {
        int leftC = leftChild(index);
        int rightC = rightChild(index);
        
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
    heap.insert(99);
    heap.insert(72);
    heap.insert(61);
    heap.insert(58);
    heap.insert(100);

    heap.print();
}