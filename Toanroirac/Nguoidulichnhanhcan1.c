#include <stdio.h>
#include <limits.h>
#include <string.h>

int n;
int c[105][105], X[100], best_path[100];
int visited[105];
int d = 0, ans = INT_MAX, dem = 0, cmin = INT_MAX;

void nhap() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
            if (c[i][j] != 0 && c[i][j] < cmin) {
                cmin = c[i][j];
            }
        }
    }
    memset(visited, 0, sizeof(visited));
}

void copy_path() {
    for (int i = 1; i <= n; i++) {
        best_path[i] = X[i];
    }
}

void Try(int i) {
    dem++;
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            visited[j] = 1;
            X[i] = j;
            d += c[X[i - 1]][X[i]];

            if (i == n) {
                int cost = d + c[X[n]][X[1]];
                if (cost < ans) {
                    ans = cost;
                    copy_path(); // lưu lại đường đi tốt nhất
                }
            } else if (d + (n - i + 1) * cmin < ans) {
                Try(i + 1);
            }

            visited[j] = 0;
            d -= c[X[i - 1]][X[i]];
        }
    }
}

void in_duong_di() {
    printf("Duong di tot nhat: ");
    for (int i = 1; i <= n; i++) {
        printf("%d -> ", best_path[i]);
    }
    printf("%d\n", best_path[1]); // quay lại điểm xuất phát
}

int main() {
    nhap();
    X[1] = 1;
    visited[1] = 1;
    Try(2);
    printf("Chi phi nho nhat: %d\n", ans);
    in_duong_di();
    printf("So lan goi ham Try: %d\n", dem);
    return 0;
}


