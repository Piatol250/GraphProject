#ifndef GRAPH_H
#define GRAPH_H

typedef struct edge {
    int to_vertex;
    int weight;
} Edge;

typedef struct edgeNode {
    Edge edge;
    struct edgeNode* next;
} *EdgeNodePtr;

typedef struct edgeList {
    EdgeNodePtr head;
} EdgeList;

typedef struct graph {
    int V;
    EdgeList* edges;
} Graph;

Graph* readGraphFromFileTutorialExample(const char* filename);
Graph* readGraphFromFileRLExample(const char* filename);
Graph* createGraph(int V);
void addEdge(Graph* graph, int from_vertex, int to_vertex, int weight);
void destroyGraph(Graph* graph);
void printInDegree(Graph* graph);

#endif /* GRAPH_H */