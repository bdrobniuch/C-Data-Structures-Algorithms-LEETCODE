#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertionSort(vector<int> &v)
{
    for (auto it = v.begin() + 1; it != v.end(); ++it)
    {
        auto it2 = it;

        for (auto i : v)
            cout << i << ", ";
        cout << " temp" << endl;

        while (it2 != v.begin()+1)
        {
            if (*it2 > *(it2 - 1))
            {

                break;
            }
            --it2;
        }
        swap(*it, *it2);
    }
}

int main()
{
    vector<int> v = {4, 2, 6, 5, 1, 3};

    for (auto i : v)
        cout << i << ", ";
    cout << endl;

    insertionSort(v);

    for (auto i : v)
        cout << i << ", ";
    cout << endl;
}