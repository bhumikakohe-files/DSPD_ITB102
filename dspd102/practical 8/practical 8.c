

#include <stdio.h>
#include <stdlib.h>
int v,i
typedef struct {
    int src, dest, weight;
} Edge;


typedef struct {
    int parent;
    int rank; 
} Subset;


int find(Subset subsets[], int i) {
   
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}


int compareEdges(const void* a, const void* b) {
    Edge* a1 = (Edge*)a;
    Edge* b1 = (Edge*)b;
    return a1->weight - b1->weight;
}



void KruskalMST(int V, int E, Edge edges[]) {
   
    qsort(edges, E, sizeof(Edge), compareEdges);

   
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));

    
    for (v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    Edge* result = (Edge*)malloc((V - 1) * sizeof(Edge)); 
    int edge_count = 0; 
    int edge_index = 0; 
   
    while (edge_count < V - 1 && edge_index < E) {

        Edge next_edge = edges[edge_index++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        
        if (x != y) {
            result[edge_count++] = next_edge;
            Union(subsets, x, y); 
        }
       
    }

    // Print the MST
    printf("\nEdges in the Minimum Spanning Tree:\n");
    int min_cost = 0;
    for (i = 0; i < edge_count; i++) {
        printf("%d -- %d : %d\n", result[i].src, result[i].dest, result[i].weight);
        min_cost += result[i].weight;
    }
    printf("Minimum Cost Spanning Tree: %d\n", min_cost);

    free(subsets);
    free(result);
}

int main() {
    int V = 4; 
    int E = 5;

    Edge edges[E];

    // Example Graph (edges: src, dest, weight)
    edges[0] = (Edge){0, 1, 10};
    edges[1] = (Edge){0, 2, 6};
    edges[2] = (Edge){0, 3, 5};
    edges[3] = (Edge){1, 3, 15};
    edges[4] = (Edge){2, 3, 4};

    printf("Graph with %d vertices and %d edges.\n", V, E);

    KruskalMST(V, E, edges);

    return 0;
}



