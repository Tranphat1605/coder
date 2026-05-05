#include <iostream>
#include <string>
using namespace std;

class CTKH {
protected:
    string maCT;
    int namXB;
    bool kv;
public:
    CTKH(string maCT = "", int namXB = 0, bool kv = false) {
        this->maCT = maCT;
        this->namXB = (namXB >= 1900) ? namXB : 1900;
        this->kv = kv;
    }
    virtual void nhap() {
        cout << "Nhap ma CT: "; cin >> maCT;
        cout << "Nhap nam xuat ban: "; cin >> namXB;
        if (namXB < 1900) namXB = 1900;
        int tmp;
        cout << "Nhap khu vuc (1: Quoc te, 0: Trong nuoc): ";
        cin >> tmp;
        kv = (tmp == 1);
    }
    virtual void xuat() {
        cout << "Ma CT: " << maCT << endl;
        cout << "Nam xuat ban: " << namXB << endl;
        cout << "Khu vuc: " << (kv ? "Quoc te" : "Trong nuoc") << endl;
    }
    virtual ~CTKH() {}
};

class Baibao : public CTKH {
private:
    string tenTG;
    int soTG;
public:
    Baibao(string maCT = "", int namXB = 0, bool kv = false, string tenTG = "", int soTG = 0)
        : CTKH(maCT, namXB, kv), tenTG(tenTG), soTG(soTG) {}
    void nhap() override {
        cout << "\n=== Nhap thong tin Bai Bao ===\n";
        CTKH::nhap();
        cin.ignore();
        cout << "Nhap ten tac gia: ";
        getline(cin, tenTG);
        cout << "Nhap so tac gia: ";
        cin >> soTG;
    }
    void xuat() override {
        cout << "\n[Bai Bao]\n";
        CTKH::xuat();
        cout << "Ten tac gia: " << tenTG << endl;
        cout << "So tac gia: " << soTG << endl;
    }
    ~Baibao() {}
};

class Sach : public CTKH {
private:
    string loaisach;
public:
    Sach(string maCT = "", int namXB = 0, bool kv = false, string loaisach = "")
        : CTKH(maCT, namXB, kv), loaisach(loaisach) {}
    void nhap() override {
        cout << "\n=== Nhap thong tin Sach ===\n";
        CTKH::nhap();
        cin.ignore();
        cout << "Nhap loai sach: ";
        getline(cin, loaisach);
    }
    void xuat() override {
        cout << "\n[Sach]\n";
        CTKH::xuat();
        cout << "Loai sach: " << loaisach << endl;
    }
    ~Sach() {}
};

struct node {
    CTKH* data;
    node* next;
    node(CTKH* a) {
        data = a;
        next = NULL;
    }
};

class listCTKH {
private:
    node* head;
    int soluong;
public:
    listCTKH() {
        head = NULL;
        soluong = 0;
    }
    void them(CTKH* a) {
        node* p = new node(a);
        p->next = head;
        head = p;
        soluong++;
    }
    void xuat() {
        node* p = head;
        cout << "\n=== Danh sach Cong Trinh Khoa Hoc ===\n";
        while (p != NULL) {
            p->data->xuat();
            p = p->next;
        }
        cout << "Tong so cong trinh: " << soluong << endl;
    }
    ~listCTKH() {
        node* p = head;
        while (p != NULL) {
            node* q = p;
            p = p->next;
            delete q->data;
            delete q;
        }
    }
};

class LLKHCaNhan {
private:
    string ten;
    listCTKH ds;
public:
    void nhap() {
        cout << "Ten ca nhan: ";
        getline(cin, ten);
        int n;
        cout << "Nhap so luong cong trinh khoa hoc: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            int loai;
            cout << "\nNhap loai cong trinh thu " << i + 1 << " (1: Bai Bao, 2: Sach): ";
            cin >> loai;
            CTKH* p;
            if (loai == 1)
                p = new Baibao();
            else
                p = new Sach();
            p->nhap();
            ds.them(p);
        }
    }
    void xuat() {
        cout << "\n=== Ly lich khoa hoc cua: " << ten << " ===\n";
        ds.xuat();
    }
};

int main() {
    LLKHCaNhan llkh;
    cout << "=== Nhap thong tin ca nhan ===\n";
    llkh.nhap();
    llkh.xuat();
    return 0;
}
