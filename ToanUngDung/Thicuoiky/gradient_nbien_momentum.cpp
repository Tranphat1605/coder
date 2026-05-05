// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <iomanip>

// using namespace std;

// // Đạo hàm riêng theo x: df/dx = 2(x-3)
// double gradX(double x) { return 2 * (x - 3); }

// // Đạo hàm riêng theo y: df/dy = 2(y-5)
// double gradY(double y) { return 2 * (y - 5); }

// int main() {
//     // --- THIẾT LẬP THAM SỐ ---
//     double x = 0.0, y = 0.0;     // Tọa độ khởi đầu (0, 0)
//     double vx = 0.0, vy = 0.0;   // Vận tốc tích lũy cho từng biến
//     double alpha = 0.1;          // Tốc độ học
//     double gamma = 0.9;          // Hệ số quán tính
//     int iterations = 1000;
//     double epsilon = 1e-6;

//     cout << fixed << setprecision(4);
//     cout << "--- MOMENTUM GRADIENT DESCENT (NHIEU BIEN) ---" << endl;
//     cout << "------------------------------------------------------" << endl;

//     for (int i = 0; i < iterations; i++) {
//         // 1. Tính Gradient hiện tại
//         double gx = gradX(x);
//         double gy = gradY(y);

//         // 2. Cập nhật vận tốc (Momentum) cho từng biến độc lập
//         vx = gamma * vx + alpha * gx;
//         vy = gamma * vy + alpha * gy;

//         // 3. Cập nhật vị trí dựa trên vận tốc
//         x = x - vx;
//         y = y - vy;

//         double norm_grad = sqrt(gx * gx + gy * gy);
//         cout << i << "\t" << "x = " << x << "\t" << "y = " << y << "\t" << "Norm Gradient = " << norm_grad << endl;

//         // Kiểm tra điều kiện hội tụ (Độ dài vector Gradient)
//         if (norm_grad < epsilon) {
//             cout << "------------------------------------------------------" << endl;
//             cout << "==> Hoi tu tai buoc " << i << ": x = " << x << ", y = " << y << endl;
//             break;
//         }
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// 1. ĐỊNH NGHĨA HÀM MỤC TIÊU f(x, y)
// Em chỉ cần thay đổi nội dung hàm này, code sẽ tự tính đạo hàm tương ứng
double f(double x, double y) {
    return pow(x*x+y-11,2) + pow(x+y*y-7,2);
}

int main() {
    // --- THIẾT LẬP THAM SỐ ---
    double x = 0.0, y = 0.0;     // Tọa độ khởi đầu
    double vx = 0.0, vy = 0.0;   // Vận tốc (Momentum)
    double alpha = 0.1;          // Tốc độ học
    double gamma = 0.001;          // Hệ số quán tính
    int iterations = 1000;
    double epsilon = 1e-6;
    double h = 1e-7;             // Khoảng cách cực nhỏ để tính đạo hàm số

    cout << fixed << setprecision(4);
    cout << "--- MOMENTUM GD VOI DAO HAM SO TU DONG ---" << endl;
    cout << "------------------------------------------------------" << endl;

    for (int i = 0; i < iterations; i++) {
        double gx = (f(x + h, y) - f(x, y)) / h;
        double gy = (f(x, y + h) - f(x, y)) / h;

        // 3. CẬP NHẬT MOMENTUM (Giữ nguyên logic của em)
        vx = gamma * vx + alpha * gx;
        vy = gamma * vy + alpha * gy;

        // 4. CẬP NHẬT VỊ TRÍ
        x = x - vx;
        y = y - vy;

        double norm_grad = sqrt(gx * gx + gy * gy);
        

            cout << "Buoc " << i << ": x = " << x << "\t y = " << y 
                 << "\t f(x,y) = " << f(x, y) << endl;


        // Kiểm tra điều kiện hội tụ
        if (norm_grad < epsilon) {
            cout << "------------------------------------------------------" << endl;
            cout << "==> Hoi tu tai buoc " << i << ": x = " << x << ", y = " << y << endl;
            cout << "Gia tri f(x,y) cuoi cung: " << f(x, y) << endl;
            break;
        }
    }

    return 0;
}