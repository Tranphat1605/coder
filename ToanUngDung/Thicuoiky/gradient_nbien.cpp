// #include <iostream>
// #include <cmath>
// #include <vector>

// using namespace std;

// // Đạo hàm riêng theo từng biến
// double gradX(double x) { return 2 * (x - 3); }
// double gradY(double y) { return 2 * (y - 5); }

// void momentumMulti() {
//     double x = 0.0, y = 0.0; // Điểm khởi đầu (0,0)
//     double vx = 0.0, vy = 0.0; // Vận tốc cho từng chiều
//     double alpha = 0.1;
//     double gamma = 0.9;
//     int iterations = 100;

//     cout << "\n--- MOMENTUM HAM NHIEU BIEN ---" << endl;
//     for (int i = 0; i < iterations; i++) {
//         // 1. Tính Gradient hiện tại
//         double gx = gradX(x);
//         double gy = gradY(y);

//         // 2. Cập nhật vận tốc tích lũy (Momentum) cho từng trục
//         vx = gamma * vx + alpha * gx;
//         vy = gamma * vy + alpha * gy;

//         // 3. Cập nhật vị trí mới dựa trên vận tốc
//         x = x - vx;
//         y = y - vy;

        
//         cout << "Buoc " << i << ": x = " << x << ", y = " << y << endl;
        

//         // Kiểm tra độ dài vector Gradient (L2 Norm)
//         if (sqrt(gx*gx + gy*gy) < 1e-6) {
//             cout << "Hoi tu tai x = " << x << ", y = " << y << endl;
//             break;
//         }
//     }
// }

// int main() {
//     momentumMulti();
//     return 0;
// }



#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 1. CHỈ CẦN ĐỊNH NGHĨA HÀM f(x, y) Ở ĐÂY
// Ví dụ: f(x, y) = (x-3)^2 + (y-5)^2. Đáy tại (3, 5)
double f(double x, double y) {
    return pow(x - 3, 2) + pow(y - 5, 2);
}

// 2. TỰ ĐỘNG TÍNH ĐẠO HÀM RIÊNG THEO X
double partial_derivative_x(double x, double y) {
    double h = 1e-7;
    return (f(x + h, y) - f(x, y)) / h;
}

// 3. TỰ ĐỘNG TÍNH ĐẠO HÀM RIÊNG THEO Y
double partial_derivative_y(double x, double y) {
    double h = 1e-7;
    return (f(x, y + h) - f(x, y)) / h;
}

int main() {
    // --- THIẾT LẬP THAM SỐ ---
    double x = 0.0, y = 0.0;     // Tọa độ khởi đầu
    double vx = 0.0, vy = 0.0;   // Vận tốc (Momentum)
    double alpha = 0.1;          // Tốc độ học
    double gamma = 0.9;          // Hệ số quán tính
    int iterations = 1000;
    double epsilon = 1e-6;

    cout << fixed << setprecision(4);
    cout << "--- MOMENTUM GD VOI DAO HAM SO (2 BIEN) ---" << endl;
    cout << "Buoc\t x\t y\t f(x,y)" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < iterations; i++) {
        // Tự động lấy Gradient mà không cần giải tay
        double gx = partial_derivative_x(x, y);
        double gy = partial_derivative_y(x, y);

        // Thuật toán Momentum
        vx = gamma * vx + alpha * gx;
        vy = gamma * vy + alpha * gy;

        x = x - vx;
        y = y - vy;

        // In ra giá trị hàm số f(x, y) để theo dõi độ giảm
        if (i % 10 == 0) {
            cout << i << "\t" << x << "\t" << y << "\t" << f(x, y) << endl;
        }

        // Điều kiện dừng: Norm của Gradient đủ nhỏ
        if (sqrt(gx * gx + gy * gy) < epsilon) {
            cout << "--------------------------------------------" << endl;
            cout << "==> Hoi tu tai x = " << x << ", y = " << y << endl;
            cout << "Gia tri thap nhat f(x,y) = " << f(x, y) << endl;
            break;
        }
    }
    return 0;
}




