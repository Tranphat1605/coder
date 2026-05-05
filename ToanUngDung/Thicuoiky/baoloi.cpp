#include <iostream> 
#include <cmath> 
using namespace std; 
 
struct Point { 
    int x, y; 
}; 
 
int cross(Point A, Point B, Point C) { 
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x); 
} 
 
int dist(Point A, Point B) { 
    return (B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y); 
} 
 
void swap(Point &a, Point &b) { 
    Point tmp = a; 
    a = b; 
    b = tmp; 
} 
 
// Hàm sắp xếp các điểm theo góc quét từ P0
void sortByAngle(Point P[], int n, Point P0) {   // Sắp xếp các điểm theo góc quét từ P0
    for(int i=1; i<n-1; i++) { 
        for(int j=i+1; j<n; j++) { 
            int c = cross(P0, P[i], P[j]); 
            if(c < 0 || (c == 0 && dist(P0,P[i]) > dist(P0,P[j]))) { 
                swap(P[i], P[j]); 
            } 
        } 
    } 
} 
 
double polygonArea(Point hull[], int m) {    // Tính diện tích đa giác từ các điểm trên bao lồi
    double area = 0; 
    for(int i=0; i<m; i++) { 
        int j = (i+1) % m; 
        area += (hull[i].x * hull[j].y) - (hull[j].x * hull[i].y); 
    } 
    return fabs(area) / 2.0; 
} 
 
double distance(Point A, Point B) { 
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y)); 
} 
 
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
    // 1. Khởi tạo dữ liệu sẵn (Input giả định)
    Point P[] = {
            {1,0}, {4,0}, {6,2},{5,5},{3,6},{0,3},{2,0},{0,2},{3,3},{4,1},{2,2},{4,4},{2,4},{1,2},{1,5},{3,1},{3,5},{5,3}                  // 2 điểm nằm bên trong
    }; 
    
    // Tự động tính số lượng điểm n
    int n = sizeof(P) / sizeof(P[0]); 

    cout << "Su dung du lieu co san voi " << n << " diem." << endl;

    // --- Giữ nguyên logic Graham Scan phía dưới ---
    int ymin = P[0].y, min_idx = 0; 
    for(int i=1; i<n; i++) { 
        if(P[i].y < ymin || (P[i].y == ymin && P[i].x < P[min_idx].x)) { 
            ymin = P[i].y; 
            min_idx = i; 
        } 
    }


    
    // int n; 
    // cout << "Nhap so diem: "; 
    // cin >> n; 
 
    // Point P[100]; 
    // cout << "Nhap toa do cac diem:\n"; 
    // for(int i=0; i<n; i++) cin >> P[i].x >> P[i].y; 
    // int ymin = P[0].y, min_idx = 0; 
    // for(int i=1; i<n; i++) { 
    //     if(P[i].y < ymin || (P[i].y == ymin && P[i].x < P[min_idx].x)) { 
    //         ymin = P[i].y; 
    //         min_idx = i; 
    //     } 
    // } 
    swap(P[0], P[min_idx]); 
    Point P0 = P[0]; 
 
    sortByAngle(P, n, P0); 
 
    Point hull[100]; 
    int m = 0; 
    hull[m++] = P[0]; 
    hull[m++] = P[1]; 
    hull[m++] = P[2]; 
 
    for(int i=3; i<n; i++) { 
        while(m >= 2 && cross(hull[m-2], hull[m-1], P[i]) <= 0) { 
            m--; 
        } 
        hull[m++] = P[i]; 
    } 
 
    cout << "Cac diem tren bao loi la:\n"; 
    for(int i=0; i<m; i++) { 
        cout << "(" << hull[i].x << "," << hull[i].y << ")\n"; 
    } 
 
    cout << "Dien tich cua bao loi la: " << polygonArea(hull, m) << endl; 
    closestPair(hull, m); 
 
    return 0; 
}



// Thuật toán Graham Scan để tìm bao lồi và tính diện tích, khoảng cách hai điểm gần nhất trên bao lồi
// Bước 1: Tìm điểm có tung độ nhỏ nhất (P0)     
// Bước 2: Sắp xếp các điểm theo góc quét từ P0
// Bước 3: Khởi tạo bao lồi với 3 điểm đầu tiên
// Bước 4: Duyệt các điểm còn lại và xây dựng bao lồi
// Bước 5: Tính diện tích bao lồi    
// Bước 6: Tìm hai điểm gần nhau nhất trên bao lồi
// Hàm sắp xếp các điểm theo góc quét từ P0
// Hàm tính diện tích đa giác từ các điểm trên bao lồi
// Hàm tính khoảng cách giữa hai điểm
// Hàm tìm hai điểm gần nhau nhất trên bao lồi


