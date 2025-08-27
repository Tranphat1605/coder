#include <stdio.h>
#include <stdlib.h>

#define INF 10001 

typedef struct {
    int dinh, trongso;
} Edge;

typedef struct {
    int vertex, distance;
} Node;

void dijkstra(int start, int n, Edge **A, int *canhke, int end) {
    int d[n];
    int visited[n];
    int prev[n];
    
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }
    
    d[start] = 0;
    
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || d[j] < d[u])) {
                u = j;
            }
        }
        
        if (d[u] == INF) break;
        
        visited[u] = 1;
        
        for (int j = 0; j < canhke[u]; j++) {
            int v = A[u][j].dinh;
            int trongso = A[u][j].trongso;
            if (d[u] + trongso < d[v]) {
                d[v] = d[u] + trongso;
                prev[v] = u;
            }
        }
    }
    
    printf("Khoang cach tu a den h: ");
    if (d[end] == INF) printf("Vo cuc\n");
    else printf("%d\n", d[end]);
    
    printf("Duong di tu a den h: ");
    int path[n];
    int path_len = 0;
    int current = end;
    
    while (current != -1) {
        path[path_len++] = current;
        current = prev[current];
    }
    
    char doichu[] = {'a', 'b', 'c', 'd', 'e', 'g', 'h', 'k', 'm', 'n'};
    for (int i = path_len - 1; i >= 0; i--) {
        printf("%c", doichu[path[i]]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}

int main() {
    int n = 10;
    int m = 12;
    
    Edge *A[n];
    int canhke[n];
    for (int i = 0; i < n; i++) {
        A[i] = malloc(m * sizeof(Edge));
        canhke[i] = 0;
    }
    
    int edges[12][3] = {
        {0, 1, 1},
        {0, 4, 3},
        {0, 9, 2},
        {1, 2, 4},
        {1, 4, 1},
        {2, 3, 6},
        {2, 5, 2},
        {3, 6, 2},
        {4, 5, 4},
        {5, 6, 3},
        {6, 7, 1},
        {7, 8, 3}
    };
    
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int trongso = edges[i][2];
        A[u][canhke[u]++] = (Edge){v, trongso};
        A[v][canhke[v]++] = (Edge){u, trongso};
    }
    
    int start = 0;
    int end = 6;
    
    dijkstra(start, n, A, canhke, end);
    
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    
    return 0;
}