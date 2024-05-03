#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    Graph* G; 

    G = readGraphFromFileTutorialExample("Graph.txt");
    printInDegree(G);
    return 0;
}
