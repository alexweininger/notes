# Graphs

## Terminology

vertex: A node or point on a graph.

edge: A connection between vertices on a graph.

directed: edges are given direction

An **undirected** graph has edges that do not have direction.

The **degree** of a vertex is the number of edges connect to it.

A vertex has a **predecessor** which is the vertex that goes to the vertex.

Successors: vertex that can be accessed from this vertex

A graph is connected if there are no unreachable vertices.

A graph is **acyclic** if it has not loops or cycles.

Edges can have weight or cost. A graph with weighted edges is called a **weighted** graph.

Two vertices are **adjacent** if they share an undirected edge. Or in the case of a directed graph, vertex X is **adjacent** to vertex Y if there is an edge from Y to X.

A **sparse** graph is a graph that has few edges compared to the number of vertices in the graph.

A **dense** graph is a graph that has lots of edges compared to the number of vertices in the graph.

## Bellman-Ford algorithm

The Bellman-Ford finds the shortest path from a vertex to all other vertices. It does not require non-negative weights. And if the graph contains a **negative-weight cycle** it will detect that there is no solution.

BF algorithm will make `n-1` passes over all the edges.

And then a final 'check' pass will make sure there are no negative-weight cycles.

The order in which edges are relaxed does not matter, the result will be the same.

## Minimum cost spanning trees

Given a graph G, a **spanning tree** of G is a subgraph of G containing all the vertices, but only those edges needed for form a free tree.

N vertices will have n-1 edges.

If the graph is **weighted**, the **cost** of a spanning tree is the sum of all the edges.

A **minimum-cost spanning tree (MST)** is one with the lowest cost of all possible spanning trees. There may be more than one MST for a given graph.

MST have useful applications, e.g. the minimum amount of wire to connect a few computers, etc.

### Prim's algorithm

Prim's algorithm starts off with any vertex as the first vertex, and grows one vertex at a time.

### Kruskal's algorithm

Steps for finding the minimum spanning tree using Kruskal's algorithm:

1. Sort all the edges in non-decreasing order of their weight.

2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.

3. Repeat step#2 until there are (V-1) edges in the spanning tree.
