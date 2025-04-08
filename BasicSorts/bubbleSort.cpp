#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSort(vector<int> &v)
{
    for (int j = 1; j < v.size(); j++)
    {
        for (auto i = v.begin(); i < v.end() - j; i++)
        {
            if (*i > *(i + 1))
                std::swap(*i, *(i + 1));
        }
    }
}

int main()
{
    vector<int> v = {4, 2, 6, 5, 1, 3};

    for (auto i : v)
        cout << i << ", ";
    cout << endl;

    bubbleSort(v);

    for (auto i : v)
        cout << i << ", ";
    cout << endl;
}