#include <stdio.h>
#include <stdlib.h>

#define INF 10001

typedef struct {
    int dinh, trongso;
} Edge;

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

        if (u == -1 || d[u] == INF) break;

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

    printf("Khoang cach tu %c den %c: ", 'a' + start, 'a' + end);
    if (d[end] == INF) printf("Vo cuc\n");
    else printf("%d\n", d[end]);

    printf("Duong di tu %c den %c: ", 'a' + start, 'a' + end);
    int path[n];
    int path_len = 0;
    int current = end;

    while (current != -1) {
        path[path_len++] = current;
        current = prev[current];
    }

    for (int i = path_len - 1; i >= 0; i--) {
        printf("%c", 'a' + path[i]);
        if (i > 0) printf(" -> ");
    }
    printf("\n");
}

int main() {
    int n, m;
    printf("Nhap so dinh (toi da 26 dinh): ");
    scanf("%d", &n);
    printf("Nhap so canh: ");
    scanf("%d", &m);

    Edge *A[n];
    int canhke[n];
    for (int i = 0; i < n; i++) {
        A[i] = malloc(m * sizeof(Edge));
        canhke[i] = 0;
    }

    printf("Nhap cac canh (dinh1 dinh2 trongso), vi du: a b 3:\n");
    for (int i = 0; i < m; i++) {
        char ch1, ch2;
        int trongso;
        scanf(" %c %c %d", &ch1, &ch2, &trongso);
        int u = ch1 - 'a';
        int v = ch2 - 'a';

        A[u][canhke[u]++] = (Edge){v, trongso};
        A[v][canhke[v]++] = (Edge){u, trongso}; // vì là đồ thị vô hướng
    }

    char ch_start, ch_end;
    printf("Nhap dinh bat dau: ");
    scanf(" %c", &ch_start);
    printf("Nhap dinh ket thuc: ");
    scanf(" %c", &ch_end);
    int start = ch_start - 'a';
    int end = ch_end - 'a';

    dijkstra(start, n, A, canhke, end);

    for (int i = 0; i < n; i++) {
        free(A[i]);
    }

    return 0;
}
