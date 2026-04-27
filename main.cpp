#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <cstdlib>
using namespace std;

//Update these with parameters once other files are done
void bfs(int start);
void dfs(int start);
void bellmanFord(int start);
void mst();

void buildGraph(bool onlyRed);
bool onlyRed = true;

//Times any function and returns elapsed ms
double timeIt(function<void()> fn) {
    auto start = chrono::high_resolution_clock::now();
    fn();
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}

void testTraversal(string label, int start){
    cout << label << endl;

    double bfsTime = timeIt([&]() {
        bfs(start);
    });
    
    double dfsTime = timeIt([&]() {
        dfs(start);
    });

    cout << "  BFS Time: " << bfsTime << " ms\n";
    cout << "  DFS Time: " << dfsTime << " ms\n\n";
}

void testBellmanFord(string label, int start) {
    cout << label << endl;

    double ms = timeIt([&]() {
        bellmanFord(start);
    });

    cout << "  Time: " << ms << " ms\n\n";
}

void testMST(string label) {
    cout << label << endl;

    double ms = timeIt([&]() {
        mst();
    });

    cout << "  Time: " << ms << " ms\n\n";
}

int main(){
    cout << "CAMPUS SHUTTLE NETWORK OPTIMIZATION\n\n";

    // =========================
    // SMALL GRAPH (Red Route)
    // =========================
    cout << "----- RED ROUTE (SMALL GRAPH) -----\n\n";

    buildGraph(true);

    testTraversal("Traversal Test (BFS and DFS):", 0);
    testBellmanFord("Bellman-Ford Shortest Path Test:", 0);
    testMST("Minimum Spanning Tree Test:");

    // =========================
    // LARGE GRAPH (Full Campus)
    // =========================
    cout << "\n----- FULL CAMPUS GRAPH (LARGE) -----\n\n";

    buildGraph(false);

    testTraversal("Traversal Test (BFS and DFS):", 0);
    testBellmanFord("Bellman-Ford Shortest Path Test:", 0);
    testMST("Minimum Spanning Tree Test:");

    return 0;
}
