#include <stdio.h>
#include <string.h>
 
#define INF 99999 // Giá trị đại diện cho vô cực (khoảng cách không tồn tại)
#define MAX 100   // Số đỉnh tối đa trong đồ thị
 
void floydWarshall(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX], i, j, k;
 
    // Khởi tạo ma trận khoảng cách
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];
 
    // Cập nhật ma trận khoảng cách
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
  
    // In ma trận khoảng cách ngắn nhất
    printf("Ma tran khoang cach ngan nhat:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}
 
int main() {
    int n;
    int graph[MAX][MAX];
 
    // Nhập số đỉnh
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);
 
    // Nhập ma trận trọng số
    printf("Nhap ma tran trong so (nhap %d cho vo cuc):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
 
    // Gọi hàm Floyd-Warshall
    floydWarshall(graph, n);
 
    return 0;
}
 
