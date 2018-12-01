# Graphs

## Bellman-Ford algorithm

The Bellman-Ford finds the shortest path from a vertex to all other vertices. It does not require non-negative weights. And if the graph contains a **negative-weight cycle** it will detect that there is no solution.

BF algorithm will make `n-1` passes over all the edges.

And then a final 'check' pass will make sure there are no negative-weight cycles.

The order in which edges are relaxed does not matter, the result will be the same.

## Prim's algorithm
