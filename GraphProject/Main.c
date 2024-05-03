#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    Graph* G = NULL; 
    int choice = NULL;

    printf("do you want to test the tutorial data or the real life example?\n1. Tutorial\n2. Real life\n");
    scanf_s("%d", &choice);
    if (choice == 1)
    {
        G = readGraphFromFileTutorialExample("Graph.txt");
        printInDegree(G);
    }
    else if (choice == 2) 
    {
        G = readGraphFromFileRLExample("RealLifeData.txt");
        printInDegree(G);
    }
    free(G);
    return 0;
}
