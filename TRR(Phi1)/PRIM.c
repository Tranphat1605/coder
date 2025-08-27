#include <stdio.h>
#define INF 1000000000
#define MAXN 100006
#define MAXM 200006

struct Edge {
    int to, weight, next;
};

struct Edge edges[MAXM * 2];
int head[MAXN];
int edge_count = 0;
int inMST[MAXN];
int minWeight[MAXN];
int parent_arr[MAXN];
int heap[MAXN];
int pos[MAXN];
int heap_size = 0;

void addEdge(int u, int v, int w) {
    edges[edge_count].to = v;
    edges[edge_count].weight = w;
    edges[edge_count].next = head[u];
    head[u] = edge_count++;
}

void swap(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
    pos[heap[i]] = i;
    pos[heap[j]] = j;
}

void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i, right = 2 * i + 1;
    if (left <= heap_size && minWeight[heap[left]] < minWeight[heap[smallest]])
        smallest = left;
    if (right <= heap_size && minWeight[heap[right]] < minWeight[heap[smallest]])
        smallest = right;
    if (smallest != i) {
        swap(i, smallest);
        heapifyDown(smallest);
    }
}

void heapifyUp(int i) {
    while (i > 1 && minWeight[heap[i]] < minWeight[heap[i/2]]) {
        swap(i, i/2);
        i /= 2;
    }
}

void pushHeap(int v) {
    heap[++heap_size] = v;
    pos[v] = heap_size;
    heapifyUp(heap_size);
}

int popHeap() {
    int minV = heap[1];
    heap[1] = heap[heap_size--];
    pos[heap[1]] = 1;
    heapifyDown(1);
    return minV;
}

void decreaseKey(int v, int newWeight) {
    minWeight[v] = newWeight;
    heapifyUp(pos[v]);
}

long long prim(int n) {
    long long total_weight = 0;
    for (int i = 1; i <= n; i++) {
        minWeight[i] = INF;
        parent_arr[i] = -1;
        inMST[i] = 0;
        pos[i] = 0;
    }
    minWeight[1] = 0;
    pushHeap(1);
    int num_edges = 0;
    while (heap_size > 0) {
        int u = popHeap();
        if (inMST[u]) continue;
        inMST[u] = 1;
        total_weight += minWeight[u];
        num_edges++;
        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to, w = edges[i].weight;
            if (!inMST[v] && w < minWeight[v]) {
                minWeight[v] = w;
                parent_arr[v] = u;
                if (pos[v] == 0)
                    pushHeap(v);
                else
                    decreaseKey(v, w);
            }
        }
    }
    return (num_edges == n) ? total_weight : -1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) head[i] = -1;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        addEdge(x, y, w);
        addEdge(y, x, w);
    }
    long long result = prim(n);
    if (result == -1)
        printf("IMPOSSIBLE\n");
    else
        printf("%lld\n", result);
    return 0;
}
