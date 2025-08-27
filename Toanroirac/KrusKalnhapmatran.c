#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001

typedef struct {
    char u, v;
    int w;
} edge;

edge canh[MAXN * MAXN]; // tối đa n*n cạnh
int parent[256], sz[256];
int n, m = 0; // m sẽ được đếm sau khi đọc ma trận

int cmp(const void *a, const void *b) {
    return ((edge*)a)->w - ((edge*)b)->w;
}

void make_set() {
    for (char i = 'a'; i < 'a' + n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

char find(char v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

int union_set(char a, char b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    if (sz[a] < sz[b]) {
        char temp = a;
        a = b;
        b = temp;
    }
    parent[b] = a;
    sz[a] += sz[b];
    return 1;
}

void input() {
    FILE *f = fopen("input.txt", "r");
    if (!f) {
        printf("Loi mo file input.txt\n");
        exit(1);
    }

    fscanf(f, "%d", &n);

    int w;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &w);
            if (w > 0 && i < j) { // chỉ lấy 1 cạnh cho mỗi cặp
                canh[m].u = 'a' + i;
                canh[m].v = 'a' + j;
                canh[m].w = w;
                m++;
            }
        }
    }

    fclose(f);
}

void kruskal() {
    edge mst[MAXN];
    int mst_size = 0, d = 0;

    qsort(canh, m, sizeof(edge), cmp);

    for (int i = 0; i < m; i++) {
        if (mst_size == n - 1) break;
        edge e = canh[i];
        if (union_set(e.u, e.v)) {
            mst[mst_size++] = e;
            d += e.w;
        }
    }

    FILE *f = fopen("output.txt", "w");
    if (!f) {
        printf("Loi mo file output.txt\n");
        exit(1);
    }

    if (mst_size != n - 1) {
        fprintf(f, "Ma tran khong lien thong!\n");
    } else {
        fprintf(f, "MST:\n");
        for (int i = 0; i < mst_size; i++) {
            fprintf(f, "%c %c %d\n", mst[i].u, mst[i].v, mst[i].w);
        }
        fprintf(f, "Tong trong so: %d\n", d);
    }

    fclose(f);
}

int main() {
    input();
    make_set();
    kruskal();
    return 0;
}
