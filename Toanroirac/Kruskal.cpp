#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v, w;
};

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

const int maxn = 1001;
int n, m;
int parent[maxn];
int sz[maxn];
vector<edge> canh;

void make_set() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

bool union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void input() {  // Đã sửa tên hàm
    cin >> n >> m;
    for (int i = 0; i < m; i++) {  // Sửa vòng lặp chạy từ 0 đến m-1
        int x, y, w;
        cin >> x >> y >> w;
        canh.push_back({x, y, w});
    }
}

void kruskal() {
    vector<edge> mst;
    int d = 0;
    sort(canh.begin(), canh.end(), cmp);
    for (int i = 0; i < m; i++) {
        if (mst.size() == n - 1) break;
        edge e = canh[i];
        if (union_set(e.u, e.v)) {
            mst.push_back(e);
            d += e.w;
        }
    }
    if (mst.size() != n - 1) {
        cout << "Khong tao duoc cay khung nho nhat!" << endl;
    } else {
        cout << "MST: " << endl;
        for (auto it : mst) {
            cout << it.u << " " << it.v << " " << it.w << endl;
        }
        cout << "Tong trong so: " << d << endl;  // Thêm in tổng trọng số
    }
}

int main() {
    #ifdef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    input();  // Sửa lại tên hàm
    make_set();
    kruskal();
}
