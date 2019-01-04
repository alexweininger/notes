#include <stdio.h>
#include <stdlib.h>

typedef enum { white,
               gray,
               black } COLOR;

typedef struct Graph {
  int V;   // number of vertices in G
  int **M; // 2D array of ints, adjacency matrix
} Graph;

typedef struct DFS {
  COLOR color; // white, gray, or black
  int parent;
  int discover;
  int finish;
} DFS;

Graph *createEmptyGraph(int numVertices);
int addEdge(Graph *g, int src, int dest);
int outDegree(Graph *g, int v);
int inDegree(Graph *g, int v);
int degree(Graph *g, int v);
void freeGraph(Graph *g);
void printGraph(Graph *g);
int isNeighbor(Graph *g, int x, int y);
DFS *dfsInit(Graph *g);
void dfs(Graph *g, DFS arr[], int src);
void printReversePath(Graph *g, DFS arr[], int src, int dest);
void printTopologicalSort(Graph *g, DFS arr[], int min);

Graph *createEmptyGraph(int numVertices) {
  if (numVertices <= 0) {
    return NULL;
  }
  Graph *g = (Graph *)malloc(sizeof(Graph));
  if (g == NULL) {
    return NULL;
  }
  g->V = numVertices;
  g->M = (int **)malloc(sizeof(int *) * numVertices);
  int i;
  if (g->M != NULL) {
    for (i = 0; i < numVertices; i++) {
      g->M[i] = (int *)malloc(sizeof(int) * numVertices);
      if (g->M[i] == NULL) {
        freeGraph(g);
        return NULL;
      }
    }
  }
  int j;
  for (i = 0; i < numVertices; i++) {
    for (j = 0; j < numVertices; j++) {
      g->M[i][j] = 0;
    }
  }
  return g;
}
