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
        if (adjList.count(vertex1) == 0 || adjList.count(vertex2) == 0) return false; 

        adjList.at(vertex1).insert(vertex2);
        adjList.at(vertex2).insert(vertex1);
        return true;
    }

    bool removeEdge(string vertex1, string vertex2) {
        if (adjList.count(vertex1) == 0 || adjList.count(vertex2) == 0) return false; 
        adjList.at(vertex1).erase(vertex2);
        adjList.at(vertex2).erase(vertex1);
        return true;
    }

    bool removeVertex(string vertex) {
        if (adjList.count(vertex) == 0) return false;
        adjList.erase(vertex);
        for (auto &v : adjList) {
            v.second.erase(vertex);
        }
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
        cout<<endl;
    }
};

int main () {
    Graph graph;
    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");

    graph.addEdge("A","B");
    graph.addEdge("B","D");
    graph.addEdge("A","C");
    graph.addEdge("C","D");
    graph.addEdge("A","D");
    
    graph.print();

    graph.removeVertex("D");

    graph.print();
}