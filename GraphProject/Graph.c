#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->edges = (EdgeList*)malloc(V * sizeof(EdgeList));

    for (int i = 0; i < V; i++) {
        graph->edges[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int from_vertex, int to_vertex, int weight) {
    if (from_vertex < 0 || from_vertex >= graph->V) {
        printf("Invalid source vertex\n");
        return;
    }

    EdgeNodePtr newNode = (EdgeNodePtr)malloc(sizeof(struct edgeNode));
    newNode->edge.to_vertex = to_vertex;
    newNode->edge.weight = weight;
    newNode->next = graph->edges[from_vertex].head;
    graph->edges[from_vertex].head = newNode;
}

void destroyGraph(Graph* graph) {
    if (graph == NULL) {
        return;
    }

    for (int i = 0; i < graph->V; i++) {
        EdgeNodePtr current = graph->edges[i].head;
        while (current != NULL) {
            EdgeNodePtr temp = current;
            current = current->next;
            free(temp);
        }
    }

    free(graph->edges);
    free(graph);
}

Graph* readGraphFromFileTutorialExample(const char* filename) {
    FILE* file = fopen(filename, "r");
    int from = NULL;
    int to = NULL;
    int weight = NULL;

    if (file == NULL) {
        printf("Failed to open the file.\n");
        return NULL;
    }

    int numVertices;
    fscanf(file, "%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    while (fscanf(file, "%d,%d,%d", &from, &to, &weight) == 3)
    {
        addEdge(graph, from, to, weight);
        
    }

    fclose(file);

    return graph;
}

void printInDegree(Graph* graph) {
    int* inDegree = (int*)malloc(graph->V * sizeof(int));

    // Initialize inDegree array with zeros
    for (int i = 0; i < graph->V; i++) {
        inDegree[i] = 0;
    }

    // Calculate in-degrees for each vertex
    for (int i = 0; i < graph->V; i++) {
        EdgeNodePtr current = graph->edges[i].head;
        while (current != NULL) {
            int toVertex = current->edge.to_vertex;
            inDegree[toVertex]++;
            current = current->next;
        }
    }

    // Print in-degrees
    printf("Vertex\tIn-Degree\n");
    for (int i = 0; i < graph->V; i++) {
        printf("%d\t%d\n", i, inDegree[i]);
    }

    free(inDegree);
}