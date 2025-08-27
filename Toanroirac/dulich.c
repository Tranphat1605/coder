#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max_nodes 1000 // dinh toi da
#define max_edges 20000 // canh toi da

typedef struct {
    int u, v, capacity, flow;
} vector;

vector edge[max_edges]; // manh luu danh sach canh
int edge_count = 0; // Bien dem so canh hien co
int nodes, source, sink; // so canh, dinh phat, dinh thu

int adj[max_nodes][max_nodes]; // danh sach ke luu chi so cua canh trong mang edge
int degree[max_nodes]; // luu ban bac ra cua 1 dinh
int matrix_Max_flow[max_nodes][max_nodes]; // ma tran luong cuc dai
int matrix[max_nodes][max_nodes]; // ma tran kha nang thong qua

int parent[max_nodes]; // truy vet duong di

// ktao hang doi
int queue[max_nodes];
int front, back;

// Cac ham chinh
void add_edge(int u, int v, int capacity);
int BFS();
int Ford_Fulkerson();

// Khoi cac thao tac voi hang doi
void init_queue();
int is_empty();
void add_queue(int value);
int pop_queue();

// ham chuyen sang ma tran
void translate();
void translate_1();

void solve();

int main(){
    // char filename[100];
    // printf("MENU:\n");
    // printf("1. Nhap tu ban phim: \n");
    // printf("2. Nhap tu file:\n");

    // int lc;
    // scanf("%d", &lc);
    int total_edge;
    printf("Nhap so dinh va so canh: ");
    scanf("%d%d",&nodes, &total_edge);

    memset(degree, 0, sizeof(degree));

    //nhap canh kem theo trong so
    for (int i = 0; i < total_edge; i++){
        int u, v, capacity;
        scanf("%d%d%d", &u, &v, &capacity);
        add_edge(u, v, capacity);
    }

    //Nhap dinh nguon va dinh dich
    scanf("%d%d", &source, &sink);

    solve();

    return 0;
}

// Khoi tao queue
void init_queue(){
    front = 0;
    back = 0;
}

// Ktra queue co rong ko
int is_empty(){
    return front == back;
}

// Them ptu vao queue
void add_queue(int value){
    queue[back++] = value;
}

// Lay ra phan tu dau tien
int pop_queue(){
    return queue[front++];
}

// ham them canh vao danh sach
void add_edge(int u, int v, int capacity){
    edge[edge_count] = (vector){u, v, capacity, 0};
    adj[u][degree[u]++] = edge_count;
    edge_count++;

    // them canh nguoc voi trong so ban dau = 0
    edge[edge_count] = (vector){v, u, 0, 0};
    adj[v][degree[v]++] = edge_count;
    edge_count++;
}

// Ham BFS truy vet cac canh
int BFS(){
    memset(parent, -1, sizeof(parent));
    init_queue();
    add_queue(source);
    parent[source] = -2;

    while(!is_empty()){
        int u = pop_queue(), i;
        for(i = 0; i < degree[u]; i++){
            int index = adj[u][i];
            vector *e = &edge[index];

            if(parent[e->v] == -1 && e->capacity > e->flow){
                parent[e->v] = index;
                add_queue(e->v);

                if(e->v == sink) return 1;
            }
        }
    }
    return 0;
}

int Ford_Fulkerson(){
    int max_flow = 0;
    
    while(BFS()){
        int pathflow = INT_MAX; // cap nhat luong nho nhat sau moi lan duyet

        //tim luong nho nhat tren duong tang luong theo thuat toan bottleneck 
        for(int v = sink; v != source; ){
            int index = parent[v];
            vector *e = &edge[index];
            pathflow = min(pathflow, e->capacity - e->flow);
            v = edge[index].u;
        }

        // Cap nhat do thi thang du
        for(int v = sink; v != source; ){
            int index = parent[v];
            edge[index].flow += pathflow;
            edge[index ^ 1].flow -= pathflow;
            v = edge[index].u;
        }

        max_flow += pathflow;
    }
    return max_flow;
}


void translate(){
    memset(matrix_Max_flow, 0, sizeof(matrix_Max_flow));
    for (int k = 0; k < edge_count; k +=2){
        vector *e = &edge[k];
        matrix_Max_flow[e->u][e->v] = e->flow; 
    }
}

void translate_1(){
    memset(matrix, 0, sizeof(matrix));
    for (int k = 0; k < edge_count; k +=2){
        vector *e = &edge[k];
        matrix[e->u][e->v] = e->capacity; 
    }
}

void solve(){
    printf("Luong cuc dai la: %d\n", Ford_Fulkerson());
    translate();
    translate_1();

    printf("Ma tran luong cuc dai la: \n");
    for (int i = 0; i <= nodes; i++){
        printf("%d\t", i);
    }
    printf("\n\n");
    for (int i = 1; i <= nodes; i++){
        printf("%d\t", i);
        for (int j = 1; j <= nodes; j++){
            printf("%d(%d)\t",matrix[i][j], matrix_Max_flow[i][j]);
        }
        printf("\n\n");
    }
}

// test 1
// 6 8
// 1 2 5
// 1 3 5
// 2 4 6
// 2 5 3
// 3 4 3
// 3 5 1
// 4 6 6
// 5 6 6
// 1 6

// Output: 
// Luong cuc dai la: 9
// Ma tran luong cuc dai la:
// 0       1       2       3       4       5       6

// 1       0(0)    5(5)    5(4)    0(0)    0(0)    0(0)

// 2       0(0)    0(0)    0(0)    6(3)    3(2)    0(0)

// 3       0(0)    0(0)    0(0)    3(3)    1(1)    0(0)

// 4       0(0)    0(0)    0(0)    0(0)    0(0)    6(6)

// 5       0(0)    0(0)    0(0)    0(0)    0(0)    6(3)

// 6       0(0)    0(0)    0(0)    0(0)

// test 2
// 4 5
// 1 2 3
// 1 3 2
// 2 3 1
// 2 4 2
// 3 4 3
// 1 4

// Output
// Luong cuc dai la: 5
// Ma tran luong cuc dai la:
// 0       1       2       3       4

// 1       0(0)    3(3)    2(2)    0(0)

// 2       0(0)    0(0)    1(1)    2(2)

// 3       0(0)    0(0)    0(0)    3(3)

// 4       0(0)    0(0)    0(0)    0(0)

// test 3 (khong co duong tu source toi sink)
// 4 2
// 1 2 5
// 3 4 5
// 1 4

// Output
// Luong cuc dai la: 0
// Ma tran luong cuc dai la:
// 0       1       2       3       4

// 1       0(0)    5(0)    0(0)    0(0)

// 2       0(0)    0(0)    0(0)    0(0)

// 3       0(0)    0(0)    0(0)    5(0)

// 4       0(0)    0(0)    0(0)    0(0)

// test 4
// 6 10
// 1 2 16
// 1 3 13
// 2 3 10
// 2 4 12
// 3 2 4
// 3 5 14
// 4 3 9
// 4 6 20
// 5 4 7
// 5 6 4
// 1 6

// Output
// Luong cuc dai la: 23
// Ma tran luong cuc dai la:
// 0       1       2       3       4       5       6

// 1       0(0)    16(12)  13(11)  0(0)    0(0)    0(0)

// 2       0(0)    0(0)    10(0)   12(12)  0(0)    0(0)

// 3       0(0)    4(0)    0(0)    0(0)    14(11)  0(0)

// 4       0(0)    0(0)    9(0)    0(0)    0(0)    20(19)

// 5       0(0)    0(0)    0(0)    7(7)    0(0)    4(4)

// 6       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)

// test 5
// 7 12
// 1 2 10
// 1 3 5
// 1 4 15
// 2 3 4
// 2 5 9
// 2 6 15
// 3 4 4
// 3 6 8
// 4 7 30
// 5 6 15
// 6 7 10
// 5 7 10
// 1 7

// Output
// Luong cuc dai la: 30
// Ma tran luong cuc dai la:
// 0       1       2       3       4       5       6       7

// 1       0(0)    10(10)  5(5)    15(15)  0(0)    0(0)    0(0)

// 2       0(0)    0(0)    4(0)    0(0)    9(9)    15(1)   0(0)

// 3       0(0)    0(0)    0(0)    4(4)    0(0)    8(1)    0(0)

// 4       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    30(19)

// 5       0(0)    0(0)    0(0)    0(0)    0(0)    15(0)   10(9)

// 6       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    10(2)

// 7       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)


// test 6
// 10 20
// 1 2 15
// 1 3 12
// 2 4 20
// 2 5 10
// 3 5 5
// 3 6 8
// 4 7 15
// 4 8 5
// 5 7 10
// 5 8 8
// 5 9 12
// 6 9 10
// 7 10 20
// 8 10 10
// 9 10 15
// 2 3 5
// 4 5 3
// 6 5 2
// 7 8 4
// 9 8 3
// 1 10

// Output
// Luong cuc dai la: 27
// Ma tran luong cuc dai la:
// 0       1       2       3       4       5       6       7       8       9       10

// 1       0(0)    15(15)  12(12)  0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)

// 2       0(0)    0(0)    5(0)    20(15)  10(0)   0(0)    0(0)    0(0)    0(0)    0(0)

// 3       0(0)    0(0)    0(0)    0(0)    5(5)    8(7)    0(0)    0(0)    0(0)    0(0)

// 4       0(0)    0(0)    0(0)    0(0)    3(0)    0(0)    15(15)  5(0)    0(0)    0(0)

// 5       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    10(5)   8(0)    12(0)   0(0)

// 6       0(0)    0(0)    0(0)    0(0)    2(0)    0(0)    0(0)    0(0)    10(7)   0(0)

// 7       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    4(0)    0(0)    20(20)

// 8       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    10(0)

// 9       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    3(0)    0(0)    15(7)

// 10      0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)


// test 7
// 15 30
// 1 2 20
// 1 3 15
// 2 4 10
// 2 5 10
// 3 5 10
// 3 6 10
// 4 7 5
// 4 8 5
// 5 7 5
// 5 8 5
// 5 9 5
// 6 9 5
// 6 10 5
// 7 11 10
// 8 11 5
// 8 12 5
// 9 12 5
// 9 13 5
// 10 13 10
// 11 14 10
// 12 14 5
// 12 15 5
// 13 15 10
// 14 15 5
// 2 3 5
// 4 5 3
// 6 5 2
// 7 8 4
// 9 8 3
// 12 13 2
// 1 15

// Output
// Luong cuc dai la: 20
// Ma tran luong cuc dai la:
// 0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15

// 1       0(0)    20(15)  15(5)   0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)

// 2       0(0)    0(0)    5(0)    10(10)  10(5)   0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)

// 3       0(0)    0(0)    0(0)    0(0)    10(0)   10(5)   0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)

// 4       0(0)    0(0)    0(0)    0(0)    3(0)    0(0)    5(5)    5(5)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)

// 5       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    5(0)    5(0)    5(5)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)

// 6       0(0)    0(0)    0(0)    0(0)    2(0)    0(0)    0(0)    0(0)    5(0)    5(5)    0(0)    0(0)    0(0)    0(0)    0(0)

// 7       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    4(0)    0(0)    0(0)    10(5)   0(0)    0(0)    0(0)    0(0)

// 8       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    5(0)    5(5)    0(0)    0(0)    0(0)

// 9       0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    3(0)    0(0)    0(0)    0(0)    5(0)    5(5)    0(0)    0(0)

// 10      0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    10(5)   0(0)    0(0)

// 11      0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    10(5)   0(0)

// 12      0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    2(0)    5(0)    5(5)

// 13      0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    10(10)

// 14      0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    5(5)

// 15      0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)    0(0)


// test cuối
// 8 12
// 1 2 8 
// 1 4 2
// 1 5 4
// 2 3 6
// 2 7 2
// 3 4 4
// 3 8 4
// 4 6 3
// 5 6 6
// 6 8 8
// 7 5 4
// 7 8 2
// 1 8
