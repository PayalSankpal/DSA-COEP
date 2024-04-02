#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void initGraph(graph* g, int vertices){
    g->nV=vertices;
    for (int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            g->E[i][j]=0;
        }
    }
    return;
}

void addEdge(graph* g, int v1, int v2, int weight){
    g->E[v1][v2]=weight;
    g->E[v2][v1]=weight;
    return;
}

void displayGraph(graph g){
    for (int i=0; i<g.nV; i++){
        for(int j=0; j<g.nV; j++){
            printf("%d ",g.E[i][j]);
        }
        printf("\n");
    }
}

int degree(graph g, int v){
    int count=0;
    for (int i = 0; i<g.nV; i++){
        if(g.E[v][i]!=0){
            count++;
        }
    }
    return count;
}

int adjVertices(graph g, int v1, int v2){
    return g.E[v1][v2];
}

void dfs(graph g, int v, int* visited){
    visited[v]=1;
    for (int i =0 ; i<g.nV; i++){
        if(g.E[v][i]!=0 && !visited[i]){
            dfs(g, i, visited);
        }
    }
    return;
}

int isConnected(graph g){
    int * visited = (int *)malloc(sizeof(int)* g.nV);
    for (int i = 0; i<g.nV; i++){
        visited[i]=0;
    }
    dfs(g, 0, visited);
    for(int i =0; i<g.nV; i++){
        if(!visited[i]){
            return 0;
        }
    }
    return 1;
}


void components(graph g){
    
    int cmp=1, index=0, total_count=0;

    while(total_count < g.nV){
        int flag=0;
        int * visited = (int *)malloc(sizeof(int)* g.nV);
        for (int i = 0; i<g.nV; i++){
            visited[i]=0;
        }
        dfs(g, index, visited);
        int count=0;
        for(int i =0; i<g.nV; i++){
            if(!visited[i] && !flag){
                flag=1;
                index=i;
            }
            else if(visited[i]){
                count++;
            }
        }
        printf("%d : %d\n", cmp, count);
        total_count+=count;
        cmp+=1;
    }
    return ;
}