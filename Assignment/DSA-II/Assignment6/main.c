#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    const char* file_path = argv[1];

    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int num_vertices, num_edges;
    fscanf(file, "%d %d", &num_vertices, &num_edges);

    graph g1;
    initGraph(&g1, num_vertices);

    int v1, v2, weight;
    for (int i = 0; i < num_edges; i++) {
        fscanf(file, "%d %d %d", &v1, &v2, &weight);
        addEdge(&g1, v1, v2, weight);
    }

    fclose(file);

    displayGraph(g1);

    if(isConnected(g1)){
        printf("The graph is connected!\n");
    }
    else{
        printf("The graph is not connected!\n");
    }

    components(g1);

    return 0;
}