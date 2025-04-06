#include<iostream>
#include<vector>

using namespace std;

class Heap {
    private:
    vector<int> heap;

    int leftChild(int index) {
        return 2*index+1;
    }

    int rightChild(int index) {
        return 2*index+2;
    }
};