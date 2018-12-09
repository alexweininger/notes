# Graph theory

## Definitions

A **walk** is a sequence of edges of a graph.

A **trail** is a distinct set of edges.

A **path** is a trail with distinct vertices.

To be **closed** means that the starting vertex is also the ending vertex.

A closed trail is called a **circuit**.

A closed path is called a **cycle**.

A graph is a **simple graph** if it has no repeated edges and no loops. Versus a multigraph.

A **separating set** of a graph is a set of vertices that disconnect the graph.

When a separating set only contains one vertex, this vertex is called a **cut-vertex**.

If deleting an edge disconnects a graph this edge is a **bridge**.

A set of edges that disconnect a graph is called a **disconnecting set**.

A minimal disconnecting set is called a **cutset**.

Let G be a connected Graph. If there exists a circuit in G which contains every edge in E(G) then G is said to be Eulerian and the circuit is called an Eulerian circuit.

Let G be a connected graph. If there exists a trail in G which contains every edge if E(G) then G is said to be **semi-Eulerian** and the trail is called an **Eulerian trail**.

_note: adding one edge to a Eulerian trail creates a Eulerian circuit._

A graph G is called **Hamiltonian** if it contains a cycle including all vertices in V(G). This cycle is called a **Hamiltonian cycle**.

_note: a Hamiltonian cycle is like a Eulerian cycle but instead of edges it uses vertices._

## Theorems

The sum of the degree of all the vertices of a graph is always even.

Any graph has an even number of odd degree vertices.

For a connected graph G, deleting any edge disconnects G if and only if G has no circuits.

A connected graph G is only connected if and only if every vertex in V(G) is of even degree.

A connected graph G is semi-Eulerian, and not Eulerian, if and only if there are exactly two vertices of odd degree in V(G).

## Proofs

**Theorem:** connected graph G is semi-Eulerian, and not Eulerian, if and only if there are exactly two vertices of odd degree in V(G).

**Proof:** In order to prove an if and only if, you must prove it both ways.

->
A semi-Eulerian graph can become a Eulerian graph by adding a single edge. All vertices of a Eulerian graph must be of even degree. Adding an edge would increase the degree of two vertices by one. Thus, a semi-Eulerian graph must have exactly two vertices of odd degree.

<-
A connected graph with exactly two vertices of odd degree is not a Eulerian graph because it has vertices of odd degree. Adding one edge to this graph connecting the two vertices of odd degree would increment the degree of both vertices by one. Thus both vertices now have even degrees. Making the graph a Eulerian graph. And the graph without the added edge is a semi-Eulerian graph.

## Topics

Graceful labelling is a way to label the vertices of a graph so that when adding up the edges and the vertex label they correspond. E.g. `0 1 3 5`.

### Hamiltonian cycles

Hamiltonian cycles, unlike Eulerian circuits have no necessary and sufficient condition. Hamiltonian cycles do have necessary conditions and sufficient conditions but not one of both like the two vertices of odd degree theorem for Eulerian circuits.

If you want to be sure you have to try all possibilities.

Parallel edges have no effect on a Hamiltonian graph.

**Ore's Theorem:** Let G be a simple connected graph where `|V(G)| = n >= 3`. If `deg(x) + deg(y) >= n` for all nonadjacent x, y that exist in V(G), then G is Hamiltonian.

_note: Ore's theorem is only a sufficient condition for a Hamiltonian cycle. Meaning a Hamiltonian graph does not have to satisfy this condition, but if a graph does, it is a Hamiltonian cycle._

**Dirac's Theorem:** If G is a connected graph on n-vertices where `n >= 3` so that for x, y of V(G), where `x != y`, and deg(x) + deg(y) >= n for all x, y of V(G), then G is a Hamiltonian graph.

_note: this theorem is still just a sufficient condition._

**Can a Hamiltonian graph have a cut-vertex?**

A cut-vertex must be the only vertex connecting two components of a graph, making them connected. Meaning the only way to get to the other component is through this vertex. Thus, once this vertex is visited it is impossible to reach the started vertex.

Therefore, a Hamiltonian graph cannot have a cut-vertex.

**Can a Hamiltonian graph have a bridge?**

A bridge is an edge that when removed disconnects an otherwise connected graph. Meaning, the only way to get to the other component of the graph is to _cross_ the bridge. This visiting the two vertices connected by the bridge is the only way to get to the other component.

Thus, once we have visited these vertices, to return to our starting vertex we must visit these vertices again. Which is in contradiction with the definition of a Hamiltonian graph.

Therefore, a Hamiltonian graph cannot have a bridge.
