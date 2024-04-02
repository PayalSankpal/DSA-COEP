typedef struct node{
    char vert;
    int weight;
    struct node* next;
}node;

typedef struct adjListnode{
    char vert;
    struct node* vertList;
}adjListnode;

typedef struct graph{
    int numVertices;
    struct adjListnode* adjList;
}graph;

void initGraph(graph* g, int nV);
void add_edge(graph* g, char v1, char v2, int weight);
void display(graph g);
void BFS(graph g, char start);
void DFS(graph* graph, char start);