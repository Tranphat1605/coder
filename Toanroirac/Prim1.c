#include <stdio.h>
#include <stdbool.h>

#define MAXN 1001
#define INF 1000000000

typedef struct {
    char x, y;
    int w;
} Canh;

int n, m;
Canh MST[MAXN];
int adj[128][128];
bool used[128];

void nhap(FILE* input) {
    fscanf(input, "%d %d", &n, &m);
    
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            adj[i][j] = INF;
        }
    }
    
    for (int i = 0; i < m; i++) {
        char x, y;
        int w;
        fscanf(input, " %c %c %d", &x, &y, &w);
        adj[x][y] = w;
        adj[y][x] = w;
    }
    
    for (int i = 0; i < 128; i++) {
        used[i] = false;
    }
}

void prim(char u, FILE* output) {
    int d = 0;
    used[u] = true;
    int mst_size = 0;
    
    while (mst_size < n - 1) {
        int min_w = INF;
        char x = '\0', y = '\0';
        
        for (char i = 'a'; i <= 'z'; i++) {
            if (used[i]) {
                for (char j = 'a'; j <= 'z'; j++) {
                    if (!used[j] && adj[i][j] < min_w) {
                        min_w = adj[i][j];
                        x = j;
                        y = i;
                    }
                }
            }
        }
        
        if (x == '\0' || y == '\0') break;
        
        MST[mst_size].x = y;
        MST[mst_size].y = x;
        MST[mst_size].w = min_w;
        mst_size++;
        d += min_w;
        used[x] = true;
    }
    
    fprintf(output, "MST:\n");
    for (int i = 0; i < mst_size; i++) {
        fprintf(output, "%c %c %d\n", MST[i].x, MST[i].y, MST[i].w);
    }
    fprintf(output, "Tong trong so: %d\n", d);
}

int main() {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    
    if (!input || !output) {
        printf("Error opening file!\n");
        return 1;
    }
    
    nhap(input);
    prim('a', output);
    
    fclose(input);
    fclose(output);
    
    return 0;
}
