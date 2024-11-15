// C++ Program to Implement Minimum Spanning Tree using
// Prim's Algorithm
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define V 5

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

// Function to print the Minimum Spanning Tree (MST)
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}

// Function to find the MST using Prim's algorithm
void primMST(int graph[V][V])
{
    int parent[V], key[V];
    bool mstSet[V];

    // Initialize key values and MST set
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0; // Start with the first vertex
    parent[0] = -1; // No parent for the first vertex

    // Construct the MST
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(
            key,
            mstSet); // Find the vertex with the minimum key
        mstSet[u] = true; // Mark it as part of the MST

        // Update key values for adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v]
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the MST
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = { { 0, 2, 3, 0, 0 },
                        { 2, 0, 0, 15, 2 },
                        { 3, 0, 0, 7, 1 },
                        { 0, 15, 7, 0, 0 },
                        { 0, 2, 1, 0, 0 } };

    primMST(graph);

    return 0;
}
