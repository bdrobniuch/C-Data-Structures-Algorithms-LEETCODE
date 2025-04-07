#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <typeinfo>

using namespace std;

class Person
{
public:
    string name;
    int height;
    friend ostream& operator<<(ostream& os, const Person& p);

};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << "Person (name: " << p.name << " height: " << p.height << ")";
    return os;
}

int main()
{
    vector<int> v({1, 0, 3, 0, 5, 0, 7, 8, 9});
    string st = "Piesek Leszek";
    unordered_set<int> s(v.begin(), v.end());

    auto first = std::find_if(v.begin(), v.end(), [](int i)
                              { return i > 3; });
    auto second = std::find_if(s.begin(), s.end(), [](int i)
                               { return i > 3; });

    cout << *first << " " << *second << endl;

    std::reverse(v.begin(), v.end());

    auto l = [&]()
    {
        for (auto i : v)
        {
            cout << i << ", ";
        }
        cout << endl;
    };
    l();

    st.erase(std::remove_if(st.begin(), st.end(), [](auto i)
                            { return i == 'L'; }),
             st.end());
    std::remove(st.begin(), st.end(), ' ');
    cout << st << endl;

    l();

    std::sort(v.begin(), v.end(), [](int a, int b)
              { return a > b; });
    l();

    std::for_each(v.begin(), v.end(), [](int &i)
                  { i = i % 3; });

    l();

    cout <<endl;

    vector<Person> persons = {{"Adam", 33}, {"Michal", 41}, {"Kasia", 12}, {"Alicja", 32}};
    std::for_each(persons.begin(), persons.end(), [](auto i) { cout << i << endl; });

    std::sort(persons.begin(), persons.end(), [](auto a, auto b){return a.height > b.height;});

    cout <<endl;

    std::for_each(persons.begin(), persons.end(), [](auto i) { cout << i << endl; });
}