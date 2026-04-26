#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <cstdlib>
using namespace std;

//Update these with parameters once other files are done
void bfs(int start);
void dfs(int start);
void dijkstra();
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

void testDijkstra(string label) {
    cout << label << endl;

    double ms = timeIt([&]() {
        //dijkstra(...);
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
    cout << "CAMPUS SHUTTLE NETWORK OPTIMIZATION";

    buildGraph(onlyRed);
    if(onlyRed == true){
        cout << " FOR RED ROUTE\n\n";
    }
    else
    {
        cout << "\n\n";
    }


    testTraversal("Traversal Test (BFS and DFS):", 0);
    testDijkstra("Dijkstra Shortest Path Test:");
    testMST("Minimum Spanning Tree Test:");

    return 0;
}
