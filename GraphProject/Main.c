#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    Graph G; 

    FILE* file = fopen("graph.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    return 0;
}
