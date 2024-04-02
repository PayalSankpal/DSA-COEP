#define MAXVertices 100

typedef struct graph{
    int nV;
    int E[MAXVertices][MAXVertices];
}graph;

void initGraph(graph* g, int vertices);
void addEdge(graph* g, int v1, int v2, int weight);
void displayGraph(graph g);
int degree(graph g, int v);
int isConnected(graph g);
void components(graph g);




