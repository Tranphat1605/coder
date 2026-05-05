#include <iostream>
#include "ResearchManager.h"
using namespace std;

string nhapChuoi(const string& msg) {
    while (true) {
        cout << msg;
        string s;
        getline(cin, s);
        while (!s.empty() && s.front() == ' ') s.erase(s.begin());
        while (!s.empty() && s.back() == ' ') s.pop_back();
        if (s.empty()) {
            cout << "Gia tri khong duoc de trong! Vui long nhap lai.\n";
            continue;
        }
        return s;
    }
}

int nhapInt(const string& msg, int minValue, int maxValue) {
    while (true) {
        cout << msg;
        int x;
        cin >> x;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Du lieu khong hop le! Vui long nhap so.\n";
            continue;
        }
        if (x < minValue || x > maxValue) {
            cout << "Gia tri phai nam trong khoang " << minValue << " - " << maxValue << ".\n";
            continue;
        }
        cin.ignore();
        return x;
    }
}

double nhapDouble(const string& msg, double minValue) {
    while (true) {
        cout << msg;
        double x;
        cin >> x;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Du lieu khong hop le! Vui long nhap so.\n";
            continue;
        }
        if (x < minValue) {
            cout << "Gia tri phai >= " << minValue << ".\n";
            continue;
        }
        cin.ignore();
        return x;
    }
}

int main() {
    ResearchManager ql;

    while (true) {
        cout << "=============== HE THONG QUAN LY CONG TRINH NGHIEN CUU ===============\n";
        cout << "1. Them cong trinh moi\n";
        cout << "2. Xoa cong trinh theo ID\n";
        cout << "3. Tim cong trinh theo ID\n";
        cout << "4. Hien thi tat ca cong trinh\n";
        cout << "5. Thong ke\n";
        cout << "6. Sap xep theo nam\n";
        cout << "7. Sap xep theo tac gia\n";
        cout << "8. Thoat\n";
        cout << "=======================================================================\n";
        int chon = nhapInt("Nhap lua chon: ", 1, 8);
        if (chon == 1) {
            int loai = nhapInt("Loai cong trinh (1=Journal, 2=Conference, 3=Grant): ", 1, 3);
            string id = nhapChuoi("Nhap ID: ");
            string ten = nhapChuoi("Nhap ten cong trinh: ");
            string tacGia = nhapChuoi("Nhap ten tac gia: ");
            int nam = nhapInt("Nhap nam (2000 - 2025): ", 2000, 2025);
            try {
                if (loai == 1) {
                    string tapChi = nhapChuoi("Nhap ten tap chi: ");
                    double impact = nhapDouble("Nhap he so anh huong (>=0): ", 0.0);
                    ql.themCongTrinh(new JournalPaper(id, ten, tacGia, nam, tapChi, impact));
                }
                else if (loai == 2) {
                    string hoiNghi = nhapChuoi("Nhap ten hoi nghi: ");
                    string diaDiem = nhapChuoi("Nhap dia diem: ");
                    ql.themCongTrinh(new ConferencePaper(id, ten, tacGia, nam, hoiNghi, diaDiem));
                }
                else {
                    double kinhPhi = nhapDouble("Nhap kinh phi (trieu dong): ", 0.0);
                    int thoiGian = nhapInt("Nhap thoi gian thuc hien (thang): ", 1, 1000);

                    ql.themCongTrinh(new ResearchGrant(id, ten, tacGia, nam, kinhPhi, thoiGian));
                }
            }
            catch (exception& e) {
                cout << "Loi: " << e.what() << "\n";
            }
        }
        else if (chon == 2) {
            string id = nhapChuoi("Nhap ID can xoa: ");
            ql.xoaCongTrinh(id);
        }
        else if (chon == 3) {
            string id = nhapChuoi("Nhap ID can tim: ");
            ql.timCongTrinh(id);
        }
        else if (chon == 4) {
            ql.hienThiTatCa();
        }
        else if (chon == 5) {
            ql.thongKe();
        }
        else if (chon == 6) {
            ql.sapXepTheoNam();
        }
        else if (chon == 7) {
            ql.sapXepTheoTacGia();
        }
        else {
            cout << "Thoat chuong trinh...\n";
            break;
        }
    }
    return 0;
}
