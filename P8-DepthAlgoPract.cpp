#include <iostream>
#include <vector>
using namespace std;

class Graph {
    vector<vector<int>> adjList;

public:
    Graph(int v) : adjList(v) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    void startDFS(int start) {
        vector<bool> visited(adjList.size(), false);
        cout << "DFS Traversal: ";
        DFS(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.startDFS(0);
    return 0;
}
