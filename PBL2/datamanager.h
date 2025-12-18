#pragma once
#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "HDVay.h"
#include "TaiKhoan.h"
#include "LKDoi.h"
#include "NhanVien.h"
#include "KhachHang.h"
#include "ThanhToan.h"

using namespace std;

class DataManager {
private:
    LinkedList<NhanVien> dsNhanVien;
    LinkedList<KhachHang> dsKhachHang;
    LinkedList<HopDongVay> dsHopDongVay;
    LinkedList<TaiKhoan> dsTaiKhoan;
    LinkedList<ThanhToan> dsThanhToan;

    
    const string nvFilename = "nhanvien.txt";
    const string khFilename = "khachhang.txt";
    const string hdvFilename = "hopdongvay.txt";
    const string tkFilename = "taikhoan.txt";
    const string ttFilename = "thanhtoan.txt";

    
    void loadNhanVien();
    void loadKhachHang();
    void loadHopDongVay();
    void loadTaiKhoan();
    void loadThanhToan();

    void saveNhanVien();
    void saveKhachHang();
    void saveHopDongVay();
    void saveTaiKhoan();
    void saveThanhToan();

public:
    DataManager(); 
    void loadAllData(); 
    void saveAllData();

    LinkedList<NhanVien>& getNhanVienList();
    LinkedList<KhachHang>& getKhachHangList();
    LinkedList<HopDongVay>& getHopDongVayList();
    LinkedList<TaiKhoan>& getTaiKhoanList();
    LinkedList<ThanhToan>& getThanhToanList();

    template <typename T>
    T* findByMa(LinkedList<T> &list, const string &ma) {
        return list.find([&](const T &obj) {
            return obj.getMa() == ma;
        });
    }
};

#endif
