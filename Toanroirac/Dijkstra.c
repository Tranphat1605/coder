#include <stdio.h>
#include <stdlib.h>

#define INF 10001

typedef struct {
    int dinh, trongso;
} Edge;

void printPathWithChar(int path[], int length, char charMap[]) {
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", charMap[path[i]]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}

void dijkstra(int start, int n, Edge **A, int *canhke, int end, char charMap[]) {
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

    printf("Khoang cach tu %c den %c: ", charMap[start], charMap[end]);
    if (d[end] == INF) printf("Vo cuc\n");
    else printf("%d\n", d[end]);

    printf("Duong di tu %c den %c: ", charMap[start], charMap[end]);
    int path[n];
    int path_len = 0;
    int current = end;

    while (current != -1) {
        path[path_len++] = current;
        current = prev[current];
    }

    printPathWithChar(path, path_len, charMap);
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    Edge *A[n];
    int canhke[n];
    for (int i = 0; i < n; i++) {
        A[i] = malloc(n * sizeof(Edge));
        canhke[i] = 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j] != 0)
                A[i][canhke[i]++] = (Edge){j, adj[i][j]};

    int start, end;
    scanf("%d %d", &start, &end);

    // Mảng ánh xạ chỉ số đỉnh sang ký tự
    char charMap[] = {'a', 'b', 'c', 'd', 'e', 'g', 'h', 'k', 'm', 'n'};

    dijkstra(start, n, A, canhke, end, charMap);

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }

    return 0;
}
