#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int v);

struct Graph {
    int numVertices;
    int* visited;
    struct node** adjList;
};

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = v;
    newNode->next = NULL;

    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjList = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for(i = 0; i < graph->numVertices; ++i) {
        graph->visited[i] = 0;
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int des) {
    struct node* newNode = createNode(des);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[des];
    graph->adjList[des] = newNode;
}

void DFS(struct Graph* graph, int src) {
    struct node* temp = graph->adjList[src];

    graph->visited[src] = 1;
    printf("Visited %d \n", src);
    while(temp != NULL) {
        int adjV = temp->data;
        if(graph->visited[adjV] == 0) {
                DFS(graph, adjV);
        }
        temp = temp->next;
    }
}
int main() {
    struct Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    DFS(graph, 1);
}

