#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int> &v)
{

    for (auto i = v.begin(); i != v.end(); ++i)
    {
       auto minE = std::min_element(i, v.end());
       if (i != minE) {
            if (*i> *minE) std::swap(*i, *minE);
       }

    }
}

int main()
{
    vector<int> v = {4, 2, 6, 5, 1, 3};

    for (auto i : v)
        cout << i << ", ";
    cout << endl;

    selectionSort(v);

    for (auto i : v)
        cout << i << ", ";
    cout << endl;
}