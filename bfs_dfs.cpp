#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

// Edge is the directed route between two stops
struct Edge{
    int to;
    int time;
    string routeName;
};

//Allow access to graph and stop names
vector<vector<Edge>>& getGraph();
vector<string>& getStops();

void bfs(int start){ 
    // Gets graph and stop names
    vector<vector<Edge>>& graph = getGraph();
    vector<string>& stops = getStops();

    // Keeps track of stops already visited
    vector<bool> visited (graph.size(), false);
    
    // Stops visited in first-in first-out order
    queue<int> q;
    
    // Visits the starting stop
    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal starting from " << stops[start] << ":\n";

    // Continue until all stops visited
    while(!q.empty()){
        int current = q.front();
        q.pop();

        cout << stops[current] << endl;

        // Check every outgoing stop from the current stop
        for(Edge edge : graph[current]){
            int neighbor = edge.to;
            
            // If outgoing stop not visited yet then do visit it
            if (!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    cout << endl;
}

void dfs(int start){
    vector<vector<Edge>>& graph = getGraph();
    vector<string>& stops = getStops();

    vector<bool> visited (graph.size(), false);
    
    // Locations visited in first-in last-out order. Most recent path first
    stack<int> s;

    s.push(start);

    cout << "DFS Traversal starting from " << stops[start] << ":\n";

    // Until all stops have been visited
    while(!s.empty()){
        int current  = s.top();
        s.pop();

        // Only visit it if the current stop has not yet been visited
        if(!visited[current]){
            visited[current] = true;
            cout << stops[current] << endl;

            // Visit every outgoing stop if not yet visited
            for(Edge edge : graph[current]){
                int neighbor = edge.to;

                if(!visited[neighbor]){
                    s.push(neighbor);
                }
            }

        }
    }
    cout << endl;

}

