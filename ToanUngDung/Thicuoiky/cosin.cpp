//ma nguon ham tinh do do
#include <vector>
#include <cmath>
using namespace std;

double cosineSimilarity(const vector<double>& x,
                        const vector<double>& y)
{
    double dot = 0.0, normX = 0.0, normY = 0.0;

    for (int i = 0; i < x.size(); i++) {
        dot   += x[i] * y[i];
        normX += x[i] * x[i];
        normY += y[i] * y[i];
    }

    return dot / (sqrt(normX) * sqrt(normY));
}


// Thuật toán tìm cặp điểm tương đồng Cosine lớn nhất

// Chuẩn hóa tất cả các điểm về độ dài 1

// Sinh một vectơ ngẫu nhiên r trong ℝ¹⁰

// Chiếu mỗi điểm lên r

// Sắp xếp các điểm theo giá trị chiếu

// Tính cosine similarity cho các cặp điểm kề nhau

// Chọn cặp có cosine lớn nhất

#include <algorithm>
#include <random>

pair<int,int> maxCosinePair(vector<vector<double>>& X)
{
    int n = X.size();
    vector<vector<double>> Xn = X;

    // Chuẩn hóa
    for (int i = 0; i < n; i++) {
        double norm = 0;
        for (double v : Xn[i]) norm += v*v;
        norm = sqrt(norm);
        for (double &v : Xn[i]) v /= norm;
    }

    // Vector ngẫu nhiên
    vector<double> r(10);
    mt19937 gen(42);
    uniform_real_distribution<double> dist(0,1);
    for (int i = 0; i < 10; i++) r[i] = dist(gen);

    // Chiếu
    vector<pair<double,int>> proj;
    for (int i = 0; i < n; i++) {
        double p = 0;
        for (int j = 0; j < 10; j++)
            p += Xn[i][j] * r[j];
        proj.push_back({p, i});
    }

    sort(proj.begin(), proj.end());

    double best = -1;
    pair<int,int> ans;

    for (int i = 0; i < n-1; i++) {
        int a = proj[i].second;
        int b = proj[i+1].second;
        double c = cosineSimilarity(X[a], X[b]);
        if (c > best) {
            best = c;
            ans = {a, b};
        }
    }
    return ans;
}
