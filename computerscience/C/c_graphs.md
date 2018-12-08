# Graphs

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
