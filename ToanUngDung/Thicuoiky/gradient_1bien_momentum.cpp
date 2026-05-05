// #include <iostream>
// #include <cmath>
// #include <iomanip>

// using namespace std;

// // Đạo hàm f'(x) = 2x - 4
// double df(double x) { 
//     return 2 * x - 4; 
// }

// int main() {
//     // --- THIẾT LẬP THAM SỐ ---
//     double x = -10.0;        // Điểm khởi đầu
//     double alpha = 0.1;      // Tốc độ học (eta)
//     double gamma = 0.9;      // Hệ số quán tính (Momentum)
//     double v = 0.0;          // Vận tốc ban đầu
//     int iterations = 100;    // Số lần lặp tối đa
//     double epsilon = 1e-6;   // Ngưỡng dừng

//     cout << fixed << setprecision(4);
//     cout << "--- MOMENTUM GRADIENT DESCENT (1 BIEN) ---" << endl;
//     cout << "Buoc\t    x\t\t  Gradient\t  Van toc" << endl;
//     cout << "----------------------------------------------------" << endl;

//     for (int i = 0; i < iterations; i++) {
//         double grad = df(x);

//         // Thuật toán Momentum
//         v = gamma * v + alpha * grad; 
//         x = x - v;

//         cout << i << "\t" << "x = " << x << "\t" << "Gradient = " << grad << "\t" << "Van toc = "
//          << v << endl;

//         // Kiểm tra hội tụ
//         if (abs(grad) < epsilon) {
//             cout << "----------------------------------------------------" << endl;
//             cout << "==> Hoi tu tai buoc: " << i << ", x = " << x << endl;
//             break;
//         }
//     }
//     return 0;
// }



#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// 1. CHỈ CẦN ĐỊNH NGHĨA HÀM f(x) Ở ĐÂY
// Ví dụ: f(x) = (x-2)^2. Cực tiểu tại x = 2
double f(double x) {
    // ln trong C++ là hàm log()
    // e^x trong C++ là hàm exp()
    return pow(log(2 * x * x + 1), 2) + 9 * x + 3 * exp(x * x) - 5;
}

int main() {
    // --- THIẾT LẬP THAM SỐ ---
    double x = 0.0;        // Điểm khởi đầu
    double alpha = 0.001;      // Tốc độ học (eta), khi tốc độ tăng càng lớn thì alpha càng nhỏ 
    double gamma = 0.9;      // Hệ số quán tính (Momentum), khi gamma tăng thì vận tốc càng được giữ lại nhiều
    double v = 0.0;          // Vận tốc ban đầu
    int iterations = 1000;   // Tăng số vòng lặp để quan sát sự hội tụ
    double epsilon = 1e-6;   // Ngưỡng dừng
    double h = 1e-7;         // Bước nhảy cực nhỏ để tính đạo hàm số

    cout << fixed << setprecision(4);
    cout << "--- MOMENTUM GD 1 BIEN VOI DAO HAM SO ---" << endl;
    cout << "Buoc\t    x\t\t Gradient\t f(x)" << endl;
    cout << "----------------------------------------------------" << endl;

    for (int i = 0; i < iterations; i++) {
        // 2. TỰ ĐỘNG TÍNH ĐẠO HÀM SỐ (Thay vì dùng hàm df giải tay)
        // f'(x) ~ [f(x + h) - f(x)] / h
        double grad = (f(x + h) - f(x)) / h;

        // 3. THUẬT TOÁN MOMENTUM (Giữ nguyên logic của em)
        v = gamma * v + alpha * grad; 
        x = x - v;

        // In ra mỗi 5 bước để dễ theo dõi
        cout << i << "\t" << x << "\t" << grad << "\t" << f(x) << endl;
        
        // Kiểm tra hội tụ dựa trên độ lớn của đạo hàm
        if (abs(grad) < epsilon) {
            cout << "----------------------------------------------------" << endl;
            cout << "==> Hoi tu tai buoc: " << i << ", x = " << x << endl;
            cout << "Gia tri f(x) toi thieu: " << f(x) << endl;
            break;
        }
    }

    return 0;
}