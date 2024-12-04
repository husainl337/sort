#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int v) : vertices(v) {
        adjMatrix.resize(v, vector<int>(v, 0));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // For undirected graph
    }

    void primMST() {
        vector<int> parent(vertices, -1);
        vector<int> key(vertices, INT_MAX);
        vector<bool> inMST(vertices, false);
        key[0] = 0; // Start from the first vertex

        for (int count = 0; count < vertices - 1; count++) {
            int minKey = INT_MAX, minIndex;

            // Find the vertex with the minimum key value
            for (int v = 0; v < vertices; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    minIndex = v;
                }
            }

            inMST[minIndex] = true; // Add the vertex to the MST

            // Update key values and parent index of the adjacent vertices
            for (int v = 0; v < vertices; v++) {
                if (adjMatrix[minIndex][v] && !inMST[v] && adjMatrix[minIndex][v] < key[v]) {
                    parent[v] = minIndex;
                    key[v] = adjMatrix[minIndex][v];
                }
            }
        }

        // Print the constructed MST
        cout << "Edge \tWeight\n";
        for (int i = 1; i < vertices; i++) {
            cout << parent[i] << " - " << i << "\t" << adjMatrix[i][parent[i]] << endl;
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST(); // Find and print the MST

    return 0;
}
