#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

struct Edge {
    int to;
    int time;
    string routeName;
};

vector<vector<Edge>>& getGraph();
vector<string>& getStops();

struct BellmanFordEdge {
    int from;
    int to;
    int time;
};

void bellmanFord(int start) {
    vector<vector<Edge>>& graph = getGraph();
    vector<string>& stops = getStops();

    vector<BellmanFordEdge> edges;

    // Flatten adjacency list into edge list
    for (int from = 0; from < graph.size(); from++) {
        for (Edge edge : graph[from]) {
            edges.push_back({ from, edge.to, edge.time });
        }
    }

    // Initialize distances and predecessors
    vector<int> dist(stops.size(), INT_MAX);
    vector<int> predecessor(stops.size(), -1);

    dist[start] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < stops.size() - 1; i++) {
        bool updated = false;

        for (BellmanFordEdge edge : edges) {
            // Relax edge if shorter path found
            if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.time < dist[edge.to]) {
                dist[edge.to] = dist[edge.from] + edge.time;
                predecessor[edge.to] = edge.from;
                updated = true;
            }
        }

        // Early exit if no updates occurred
        if (!updated) {
            break;
        }
    }

    // Check for negative weight cycles
    for (BellmanFordEdge edge : edges) {
        if (dist[edge.from] != INT_MAX && dist[edge.from] + edge.time < dist[edge.to]) {
            cout << "Negative weight cycle detected.\n";
            return;
        }
    }

    // Print shortest distances and paths
    cout << "Bellman-Ford shortest paths from " << stops[start] << ":\n";

    for (int i = 0; i < stops.size(); i++) {
        cout << stops[i] << ": ";

        if (dist[i] == INT_MAX) {
            cout << "unreachable\n";
            continue;
        }

        cout << dist[i] << " min | Path: ";

        // Reconstruct path using predecessors
        vector<int> path;
        for (int current = i; current != -1; current = predecessor[current]) {
            path.push_back(current);
        }

        reverse(path.begin(), path.end());

        for (int j = 0; j < path.size(); j++) {
            cout << stops[path[j]];

            if (j < path.size() - 1) {
                cout << " -> ";
            }
        }

        cout << endl;
    }

    cout << endl;
}
