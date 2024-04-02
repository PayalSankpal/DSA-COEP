#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

int main(){
    graph g1;
    initGraph(&g1, 9);
    add_edge(&g1, 'a', 'b', 2);
    add_edge(&g1, 'a', 'c', 4);
    add_edge(&g1, 'a', 'd', 6);
    add_edge(&g1, 'b', 'c', 5);
    add_edge(&g1, 'c', 'd', 1);
    add_edge(&g1, 'c', 'e', 2);
    add_edge(&g1, 'd', 'f', 3);
    add_edge(&g1, 'h', 'd', 4);
    add_edge(&g1, 'e', 'f', 1);
    add_edge(&g1, 'e', 'i', 3);
    add_edge(&g1, 'e', 'g', 5);
    add_edge(&g1, 'f', 'g', 4);
    // display(g1);
    BFS(g1,'a');
    DFS(&g1,'a');
    return 0;
}

