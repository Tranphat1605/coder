#include <iostream>
#include <vector>

using namespace std;

struct DataPoint {
    double x, y;
};

double lagrangeInterpolation(DataPoint points[], int n, double x) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        double term = points[i].y;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (x - points[j].x) / (points[i].x - points[j].x);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    // Cho 3 điểm: (0, 1), (1, 3), (2, 2)
    DataPoint points[] = {{0, 1}, {1, 3}, {2, 2}};
    int n = 3;

    double targetX = 1.5;
    double targetY = lagrangeInterpolation(points, n, targetX);

    cout << "Gia tri noi suy tai x = " << targetX << " la y = " << targetY << endl;

    system("pause");
    return 0;
}