#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Hàm số f(x)
double f(double x) { return x * x - 4 * x + 4; }

// Đạo hàm f'(x)
double df(double x) { return 2 * x - 4; }

void gradientDescent1D() {
    double x = -10.0;        // Khởi tạo điểm bắt đầu
    double alpha = 0.1;      // Learning rate
    int iterations = 100;    // Số lần lặp
    double epsilon = 1e-6;   // Ngưỡng dừng

    cout << "--- GD HAM 1 BIEN ---" << endl;
    for (int i = 0; i < iterations; i++) {
        double grad = df(x);
        
        // Cập nhật: x = x - alpha * f'(x)
        x = x - alpha * grad;

        // In ra tiến trình để em dễ theo dõi
        cout << "Buoc " << i << ": x = " << x << endl;

        if (abs(grad) < epsilon) {
            cout << "==> Hoi tu tai buoc: " << i << ", x = " << x << endl;
            break;
        }
    }
}

// THÊM HÀM MAIN NÀY VÀO LÀ CHẠY ĐƯỢC
int main() {
    gradientDescent1D(); // Gọi hàm em đã viết ở đây
    return 0;
}


// #include <iostream>
// #include <cmath>

// using namespace std;

// // Em chỉ cần định nghĩa hàm f(x) ở đây
// double f(double x) {
//     return x * x - 4 * x + 4; // Ví dụ: (x-2)^2
// }

// // Hàm này sẽ tự động tính đạo hàm của bất kỳ hàm f nào tại điểm x
// double numerical_derivative(double x) {
//     double h = 1e-7; // Một khoảng cách cực nhỏ
//     return (f(x + h) - f(x)) / h; 
// }

// int main() {
//     double x = 10.0;
//     double alpha = 0.1;
//     double v = 0.0, gamma = 0.9;

//     for (int i = 0; i < 100; i++) {
//         // Thay vì dùng hàm df(x) giải tay, ta dùng đạo hàm số
//         double grad = numerical_derivative(x);
        
//         v = gamma * v + alpha * grad;
//         x = x - v;

//         cout << "Buoc " << i << ": x = " << x << endl;

        
//         if (abs(grad) < 1e-6) break;
//     }

//     cout << "Ket qua toi uu x = " << x << endl;
//     return 0;
// }