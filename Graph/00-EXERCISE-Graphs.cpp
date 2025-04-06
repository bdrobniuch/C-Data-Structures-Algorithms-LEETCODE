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

    bool addEdge(string vertex1, string vertex2) {
        adjList[vertex1].insert(vertex2);
        adjList[vertex2].insert(vertex1);
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

    graph.addEdge("A","B");
    graph.addEdge("B","C");
    graph.addEdge("C","D");
    graph.addEdge("D","A");

    graph.print();
}