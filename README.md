# COT4400 Final Project - Campus Shuttle Network Optimization
Optimization of a campus shuttle network using graph algorithms (BFS, Dijkstra, MST) to improve travel efficiency and minimize route costs.
## Problem Statement
How can graph algorithms be applied to a campus shuttle transportation network to optimize student travel between locations while minimizing travel time and overall route cost?

# Overview
Efficient campus transportation is essential for reducing travel time and improving accessibility for students. In this project, we model a campus shuttle system as a graph and apply fundamental graph algorithms to analyze and optimize the network.

The goal is to determine efficient travel routes, evaluate network connectivity, and explore cost-effective ways to design or improve the shuttle system.

Graph Model
The campus shuttle system is represented as a graph:

- **Vertices:** Bus stops across campus
- **Edges:** Direct shuttle routes between stops
- **Weights:** Travel time between stops (in minutes)
- **Graph Type:** Weighted (directed or undirected depending on assumptions)

## Algorithms Implemented

### 1. Traversal Algorithms
- **Breadth-First Search (BFS)**
- **Depth-First Search (DFS)**

Used to:
- Explore the network
- Check connectivity between stops
- Identify unreachable or isolated locations

---

### 2. Shortest Path Algorithm
- **Dijkstra’s Algorithm**

Used to:
- Find the fastest route between two campus locations
- Minimize student travel time

---

### 3. Minimum Spanning Tree (MST)
- **Prim’s Algorithm or Kruskal’s Algorithm**

Used to:
- Determine the minimum-cost network needed to connect all stops
- Analyze efficient infrastructure design

---
