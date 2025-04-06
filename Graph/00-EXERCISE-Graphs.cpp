#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph
{
private:
    unordered_map<string, unordered_set<string>> adjList;

public:
    bool addVertex(string s)
    {
        if (adjList.find(s) != adjList.end())
            return false;
        adjList.insert(std::make_pair(s, unordered_set<std::string>()));
        return true;
    }
    void print()
    {
        for (auto k : adjList)
        {
            cout << k.first << ": [";
            for (auto s : k.second) {
                cout << s << ", ";
            }
            cout << "]" <<endl;
        }
    }
};

int main () {
    Graph graph;
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");

    graph.print();
}