#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

// Tích chéo AB × AC
int cross(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Khoảng cách bình phương
int dist(Point A, Point B) {
    return (B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y);
}

// Hoán đổi 2 điểm
void swap(Point &a, Point &b) {
    Point tmp = a;
    a = b;
    b = tmp;
}

// Sắp xếp theo góc cực (dùng bubble sort)
void sortByAngle(Point P[], int n, Point P0) {
    for(int i=1; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int c = cross(P0, P[i], P[j]);
            if(c < 0 || (c == 0 && dist(P0,P[i]) > dist(P0,P[j]))) {
                swap(P[i], P[j]);
            }
        }
    }
}

// Hàm tính diện tích đa giác (Shoelace formula)
double polygonArea(Point hull[], int m) {
    double area = 0;
    for(int i=0; i<m; i++) {
        int j = (i+1) % m;
        area += (hull[i].x * hull[j].y) - (hull[j].x * hull[i].y);
    }
    return fabs(area) / 2.0;
}

// Hàm tính khoảng cách 2 điểm
double distance(Point A, Point B) {
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

// Tìm hai điểm gần nhau nhất trên bao lồi
void closestPair(Point hull[], int m) {
    double minDist = 1e9;
    Point p1, p2;
    for(int i=0; i<m; i++) {
        for(int j=i+1; j<m; j++) {
            double d = distance(hull[i], hull[j]);
            if(d < minDist) {
                minDist = d;
                p1 = hull[i];
                p2 = hull[j];
            }
        }
    }
    cout << "Hai diem gan nhat tren bao loi: ("
         << p1.x << "," << p1.y << ") va ("
         << p2.x << "," << p2.y << "), khoang cach = "
         << minDist << endl;
}


int main() {
    int n;
    cout << "Nhap so diem: ";
    cin >> n;

    Point P[100];   // tối đa 100 điểm
    cout << "Nhap toa do cac diem:\n";
    for(int i=0; i<n; i++) cin >> P[i].x >> P[i].y;

    // Tìm điểm gốc P0 (y nhỏ nhất, nếu bằng thì x nhỏ nhất)
    int ymin = P[0].y, min_idx = 0;
    for(int i=1; i<n; i++) {
        if(P[i].y < ymin || (P[i].y == ymin && P[i].x < P[min_idx].x)) {
            ymin = P[i].y;
            min_idx = i;
        }
    }
    swap(P[0], P[min_idx]);
    Point P0 = P[0];

    // Sắp xếp các điểm còn lại theo góc cực
    sortByAngle(P, n, P0);

    // Graham Scan
    Point hull[100];
    int m = 0; // số điểm trong bao lồi
    hull[m++] = P[0];
    hull[m++] = P[1];
    hull[m++] = P[2];

    for(int i=3; i<n; i++) {
        while(m >= 2 && cross(hull[m-2], hull[m-1], P[i]) <= 0) {
            m--; // loại bỏ điểm cuối
        }
        hull[m++] = P[i];
    }

    // In kết quả
    cout << "Cac diem tren bao loi la:\n";
    for(int i=0; i<m; i++) {
        cout << "(" << hull[i].x << "," << hull[i].y << ")\n";
    }

    cout << "Dien tich cua bao loi la: " << polygonArea(hull, m) << endl;
    closestPair(hull, m);

    return 0;
}

// Thuật toán BaoLoi(P, n):

// Bước 1: Tìm điểm gốc P0
//     - Chọn điểm có tung độ nhỏ nhất.
//     - Nếu có nhiều điểm cùng tung độ → chọn điểm có hoành độ nhỏ nhất.
//     - Đặt P0 là điểm đầu tiên.

// Bước 2: Sắp xếp các điểm còn lại theo góc cực với P0
//     - Với mỗi cặp điểm (Pi, Pj), so sánh:
//         + Nếu P0→Pi→Pj tạo góc rẽ trái thì Pi đứng trước Pj.
//         + Nếu thẳng hàng thì chọn điểm gần P0 hơn trước.
//     - Sắp xếp dãy điểm theo quy tắc này.

// Bước 3: Khởi tạo bao lồi
//     - Tạo mảng Hull.
//     - Thêm 3 điểm đầu tiên: P0, P1, P2 vào Hull.

// Bước 4: Duyệt các điểm còn lại
//     For i từ 3 đến n-1:
//         While (Hull có ≥ 2 điểm) và (hướng rẽ từ 2 điểm cuối của Hull đến Pi là rẽ phải hoặc thẳng):
//             Loại bỏ điểm cuối khỏi Hull.
//         Thêm Pi vào Hull.

// Bước 5: Kết thúc
//     - Các điểm trong Hull chính là tập đỉnh của bao lồi theo thứ tự ngược chiều kim đồng hồ.
//     - In ra kết quả.




// Thuật toán BaoLoi(P, n):

// Bước 1: Tìm điểm gốc P0
//     - Chọn điểm có tung độ nhỏ nhất.
//     - Nếu có nhiều điểm cùng tung độ → chọn điểm có hoành độ nhỏ nhất.
//     - Đặt P0 là điểm đầu tiên.

// Bước 2: Sắp xếp các điểm còn lại theo góc cực với P0
//     - Với mỗi cặp điểm (Pi, Pj), so sánh:
//         + Nếu P0 → Pi → Pj rẽ trái → Pi đứng trước Pj.
//         + Nếu thẳng hàng → chọn điểm gần P0 hơn đứng trước.
//     - Sắp xếp dãy điểm theo quy tắc trên.

// Bước 3: Khởi tạo bao lồi
//     - Tạo mảng Hull rỗng.
//     - Thêm P0, P1, P2 vào Hull.

// Bước 4: Duyệt các điểm còn lại
//     For i từ 3 đến n-1:
//         While (Hull có ≥ 2 điểm) và (P[i] nằm bên phải hoặc thẳng hàng):
//             Xóa điểm cuối khỏi Hull.
//         Thêm P[i] vào Hull.

// Bước 5: Tính diện tích bao lồi
//     - Dùng công thức Shoelace:
//       area = 1/2 * |Σ (xi * yi+1 - xi+1 * yi)|  (với i chạy vòng qua các đỉnh của Hull)

// Bước 6: Tìm hai điểm gần nhau nhất trên Hull
//     - Duyệt tất cả cặp điểm (Hi, Hj) trong Hull.
//     - Tính khoảng cách d = sqrt((xi-xj)^2 + (yi-yj)^2).
//     - Lấy cặp có d nhỏ nhất.

// Bước 7: Xuất kết quả
//     - Các đỉnh bao lồi (Hull).
//     - Diện tích bao lồi.
//     - Hai điểm gần nhau nhất và khoảng cách giữa chúng.

