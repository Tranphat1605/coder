#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;

int n, m; // n: số lượng đỉnh, m: số lượng cạnh
vector<pair<int, int>> adj[maxn];
bool used[maxn]; // used[i] = true : i thuộc tập V(MST), used[i] = false : i thuộc tập V

struct canh {
    int x, y, w;
};

void nhap(FILE* input) {
    fscanf(input, "%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int x, y, w;
        fscanf(input, "%d %d %d", &x, &y, &w);
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    memset(used, false, sizeof(used));
}

void prim(int u, FILE* output){
    vector<canh> MST; // cây khung nhỏ nhất
    int d = 0; // chiều dài cây khung
    used[u] = true; // đưa đỉnh u vào tập V(MST)
    while(MST.size() < n - 1){
        int min_w = INT_MAX;
        int X, Y; // lưu 2 đỉnh của cạnh e
        for(int i = 1; i <= n; i++){
            if(used[i]){
                for(pair<int, int> it : adj[i]){
                    int j = it.first, trongso = it.second;
                    if(!used[j] && trongso < min_w){
                        min_w = trongso;
                        X = j; Y = i;
                    }
                }
            }
        }
        
        MST.push_back({X, Y, min_w});
        d += min_w;
        used[X] = true; // cho đỉnh X vào V(MST), loại X khỏi tập V
    }
    
    fprintf(output, "%d\n", d);
    for(canh e : MST){
        fprintf(output, "%d %d %d\n", e.x, e.y, e.w);
    }
}

int main() {
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");
    
    if (!input || !output) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    
    nhap(input);
    prim(1, output);
    
    fclose(input);
    fclose(output);
    
    return 0;
}