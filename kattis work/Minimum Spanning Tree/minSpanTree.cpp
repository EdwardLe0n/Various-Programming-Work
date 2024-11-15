// C++ Program to Implement Minimum Spanning Tree using
// Kruskal's Algorithm
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
    int src, dest, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v, int w)
    {
        edges.push_back({ u, v, w });
    }
};

class Subset {
public:
    int parent, rank;
};

// Find the parent of a subset (with path compression)
int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent
            = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union of two subsets (with rank-based optimization)
void Union(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Comparator function for sorting edges by weight
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

// Kruskal's MST algorithm
void KruskalMST(Graph& graph)
{
    vector<Edge> result;
    int V = graph.V;
    sort(graph.edges.begin(), graph.edges.end(), compare);

    Subset* subsets = new Subset[V];
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0;
    int i = 0;
    while (e < V - 1 && i < graph.edges.size()) {
        Edge next_edge = graph.edges[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y) {
            result.push_back(next_edge);
            Union(subsets, x, y);
            e++;
        }
    }

    cout << "Edge \tWeight\n";
    for (i = 0; i < result.size(); ++i)
        cout << result[i].src << " - " << result[i].dest
             << " \t" << result[i].weight << endl;
}

int main()
{
    int V = 5, E = 7;
    Graph graph(V, E);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 3, 15);
    graph.addEdge(1, 4, 2);
    graph.addEdge(2, 4, 1);
    graph.addEdge(2, 3, 7);
    graph.addEdge(3, 4, 2);

    KruskalMST(graph);

    return 0;
}
