//Made the choice to use Kruskal's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Edge {
    int to;
    int time;
    string routeName;
};

vector<vector<Edge>>& getGraph();
vector<string>& getStops();

struct MSTEdge {
    int from;
    int to;
    int time;
    string routeName;
};

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);

        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }

        return parent[node];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) {
            return false;
        }

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;
        }
        else if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        }
        else {
            parent[rootB] = rootA;
            rank[rootA]++;
        }

        return true;
    }
};

void mst() {
    vector<vector<Edge>>& graph = getGraph();
    vector<string>& stops = getStops();

    vector<MSTEdge> edges;

    // Convert adjacency list into an edge list.
    // For MST purposes, we treat the route connections as undirected.
    for (int from = 0; from < graph.size(); from++) {
        for (Edge edge : graph[from]) {
            edges.push_back({ from, edge.to, edge.time, edge.routeName });
        }
    }

    sort(edges.begin(), edges.end(), [](const MSTEdge& a, const MSTEdge& b) {
        return a.time < b.time;
    });

    DisjointSet ds(stops.size());

    vector<MSTEdge> mstEdges;
    int totalCost = 0;

    for (MSTEdge edge : edges) {
        if (ds.unite(edge.from, edge.to)) {
            mstEdges.push_back(edge);
            totalCost += edge.time;
        }

        if (mstEdges.size() == stops.size() - 1) {
            break;
        }
    }

    cout << "Kruskal Minimum Spanning Tree:\n\n";

    for (MSTEdge edge : mstEdges) {
        cout << stops[edge.from] << " -> "
             << stops[edge.to] << " | "
             << edge.time << " min | Route: "
             << edge.routeName << endl;
    }

    cout << "\nTotal MST Cost: " << totalCost << " minutes\n";
    cout << "Edges Used: " << mstEdges.size() << endl;
}
