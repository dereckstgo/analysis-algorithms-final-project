# COT4400 Final Project - Campus Shuttle Network Optimization
Optimization of a campus shuttle network using graph algorithms (BFS, Dijkstra, MST) to improve travel efficiency and minimize route costs.
## Problem Statement
How can graph algorithms be applied to a campus shuttle transportation network to optimize student travel between locations while minimizing travel time and overall route cost?

## Overview
Efficient campus transportation is essential for reducing travel time and improving accessibility for students. In this project, we model a campus shuttle system as a graph and apply fundamental graph algorithms to analyze and optimize the network.

The goal is to determine efficient travel routes, evaluate network connectivity, and explore cost-effective ways to design or improve the shuttle system.

Graph Model
The campus shuttle system is represented as a graph:

- **Vertices:** Bus stops across campus
- **Edges:** Direct shuttle routes between stops
- **Weights:** Travel time between stops (in minutes)
- **Graph Type:** Weighted (directed or undirected depending on assumptions)

## Files
| File | Description |
|---|---|
| `main.cpp` | Entry point, test cases, timing |
| `graph.cpp` | Graph construction, adjacency list setup, and helper functions for adding stops/routes |
| `bfs_dfs.cpp` | BFS and DFS implementations for traversal and connectivity analysis |
| `dijkstra.cpp` | Dijkstra’s algorithm for shortest/fastest shuttle routes |
|`mst.cpp`| Prim’s or Kruskal’s algorithm for minimum spanning tree analysis |
