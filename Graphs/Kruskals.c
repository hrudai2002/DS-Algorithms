#include <stdio.h>
#define MAX 100
typedef struct edge {
    int u, v, w;
} edge; 
typedef struct edge_list {
    edge data[MAX];
    int n;
} edge_list;

edge_list elist;
edge_list spanlist;

int Graph[MAX][MAX], n;

// All Function Declartions
void kruskal();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1,int c2);
void sort();
void print();


void kruskal() {
    int belongs[MAX], cn01, cn02;
    elist.n = 0;
    
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }
    }
    sort();
    
    for(int i = 0; i < n; ++i)
      belongs[i] = i;
    
    spanlist.n = 0;
    for(int i = 0; i < elist.n; ++i) {
        cn01 = find(belongs, elist.data[i].u);
        cn02 = find(belongs, elist.data[i].v);
        
        if(cn01 != cn02) {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n += 1;
            applyUnion(belongs, cn01, cn02);
        }
    }
    
    
}

int find(int belongs[],int vertexno) {
    return belongs[vertexno];
}

void applyUnion(int belongs[], int c1, int c2) {
    for(int i = 0; i < n; ++i) {
        if(belongs[i] == c2) 
           belongs[i] = c1;
    }
}

void sort() {
     edge temp;
    for(int i = 1; i < elist.n; ++i) {
        for(int j = 0; j < elist.n - 1; ++j) {
            if(elist.data[j].w > elist.data[j + 1].w) {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
        }
    }
}

void print() {
    int min_cost = 0;
    for(int i = 0; i < spanlist.n; ++i) {
        printf("%d - %d : %d\n", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        min_cost += spanlist.data[i].w;
    }
    printf("Spanning tree cost : %d", min_cost);
}

int main() {
    int e;
     scanf("%d %d", &n, &e);
    while(e--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Graph[u][v] = w;
        Graph[v][u] = w;
    }
    kruskal();
    print();
}
