#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

void initGraph(graph* g, int nV){
    g->numVertices = nV;
    g->adjList = (adjListnode *)malloc(nV*sizeof(adjListnode));
    for (int i = 0; i < nV; i++){
        g->adjList[i].vert=('a'+ i);
        g->adjList[i].vertList=NULL;
    }
    return;
}

node* create_node(char v, int w){
    node * nn = (node *)malloc(sizeof(node));
    if(!nn){
        return NULL;
    }
    nn->vert = v;
    nn->weight = w;
    nn->next = NULL;
    return nn;
}

void add_edge_helper(node** list,char v, int weight){
    node* p = *list;
    if(!p){
        *list = create_node(v, weight);
        return;
    }
    while(p->next){
        p=p->next;
    }
    p->next = create_node(v, weight);
    return;
}

void add_edge(graph* g, char v1, char v2, int weight){
    add_edge_helper(&(g->adjList[v1-'a'].vertList), v2, weight);
    add_edge_helper(&(g->adjList[v2-'a'].vertList), v1, weight);
}

void display(graph g){
    for (int i = 0; i<g.numVertices; i++){
        node * p = g.adjList[i].vertList;
        while(p){
            printf("%c %d ",p->vert, p->weight);
            p=p->next;
        }
        printf("\n"); 
    }
    return;
}

void BFS(graph g, char start){

    int * visited = (int *)malloc(sizeof(int)*g.numVertices);
    for(int i=0; i<g.numVertices; i++){
        visited[i]=0;
    }

    node * p = g.adjList[start-'a'].vertList;
    printf("BFS Traversal: %c ", start);
    visited[start-'a']=1;
    node* queue = NULL;
    while(p){
        if(!visited[p->vert-'a']){
            printf("%c ",p->vert);
            visited[p->vert-'a']=1;
            node *nn=create_node(p->vert,0);
            nn->next = queue;
            queue = nn;
            
        }
        p=p->next;
    }

    while(queue){
        node * p = g.adjList[queue->vert-'a'].vertList;
        queue=queue->next;
        while(p){
            if(!visited[p->vert-'a']){
                printf("%c ",p->vert);
                visited[p->vert-'a']=1;
                node *nn=create_node(p->vert,0);
                nn->next = queue;
                queue = nn;
                
            }
            p=p->next;
        }
    }
    printf("\n");
    return;
}

void DFS_recur(graph* graph, char v, int* visited) {
    visited[v-'a'] = 1;
    printf("%c ", v);

    node* temp = graph->adjList[v-'a'].vertList;
    while (temp) {
        if (!visited[temp->vert-'a']) {
            DFS_recur(graph, temp->vert, visited);
        }
        temp = temp->next;
    }
    return;
}

void DFS(graph* graph, char start) {
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    DFSUtil(graph, start, visited);
    printf("\n");
}


