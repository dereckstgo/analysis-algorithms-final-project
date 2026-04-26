#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

struct Edge{
    int to;
    int time;
    string routeName;
};

vector<vector<Edge>>& getGraph();
vector<string>& getStops();

void bfs(int start){
    vector<vector<Edge>>& graph = getGraph();
    vector<string>& stops = getStops();

    vector<bool> visited (graph.size(), false);
    queue<int> q;
    
    visited[start] = true;
    
    q.push(start);

    cout << "\nBFS Traversal starting from " << stops[start] << ":\n";

    while(!q.empty()){
        int current = q.front();
        q.pop();

        cout << stops[current] << endl;

        for(Edge edge : graph[current]){
            int neighbor = edge.to;

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
    stack<int> s;

    s.push(start);

    cout << "DFS Traversal starting from " << stops[start] << ":\n";

    while(!s.empty()){
        int current  = s.top();
        s.pop();

        if(!visited[current]){
            visited[current] = true;
            cout << stops[current] << endl;

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

