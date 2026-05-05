#include "datamanager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "NhanVien.h"
#include "KhachHang.h"
#include "HDVay.h"
#include "TaiKhoan.h"
#include "ThanhToan.h"

using namespace std;

DataManager::DataManager() 
    : nvFilename("nhanvien.txt"),   
      khFilename("khachhang.txt"),  
      hdvFilename("hopdongvay.txt"), 
      tkFilename("taikhoan.txt"),   
      ttFilename("thanhtoan.txt")   
{
   
}
void DataManager::loadAllData() {
    loadNhanVien();
    loadKhachHang();
    loadHopDongVay();
    loadTaiKhoan();
    loadThanhToan();
    cout << "Tai du lieu thanh cong!" << endl;
}
void DataManager::loadNhanVien() {
    ifstream file(nvFilename);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << nvFilename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        try {
            if (!getline(ss, token, '/') || token != "NV") {
                cerr << "Loi dinh dang (Khong phai NV), bo qua: " << line << endl;
                continue;
            }

            NhanVien nv;
            
            string ma, ten, sdt, cccd, gioiTinh, diaChi, chucVu, maBHXH;
            string ns_d, ns_m, ns_y, nvl_d, nvl_m, nvl_y;
            string luong_str, tt_str;

            if (getline(ss, ma, '/')       && getline(ss, ten, '/')     &&
                getline(ss, ns_d, '/')     && getline(ss, ns_m, '/')    && getline(ss, ns_y, '/') &&
                getline(ss, sdt, '/')      && getline(ss, cccd, '/')    && getline(ss, gioiTinh, '/') &&
                getline(ss, diaChi, '/')   && getline(ss, luong_str, '/') && getline(ss, tt_str, '/') &&
                getline(ss, nvl_d, '/')    && getline(ss, nvl_m, '/')   && getline(ss, nvl_y, '/') &&
                getline(ss, chucVu, '/')   && getline(ss, maBHXH, '/'))
            {
                Date ngaySinh(stoi(ns_d), stoi(ns_m), stoi(ns_y));
                Date ngayVaoLam(stoi(nvl_d), stoi(nvl_m), stoi(nvl_y));
                TrangThaiLamViec trangThai = static_cast<TrangThaiLamViec>(stoi(tt_str));

                nv.setMa(ma)
                  .setTen(ten)
                  .setNgaySinh(ngaySinh)
                  .setSdt(sdt)
                  .setCccd(cccd)
                  .setGioiTinh(gioiTinh)
                  .setDiaChi(diaChi)
                  .setLuong(stod(luong_str)) 
                  .setTrangThai(trangThai)   
                  .setNgayVaoLam(ngayVaoLam)
                  .setChucVu(chucVu)
                  .setMaBHXH(maBHXH);
                
                dsNhanVien.pushBack(nv);
            }
            else {
                cerr << "Loi dinh dang (Thieu truong NV), bo qua: " << line << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Loi khi doc dong trong " << nvFilename << ": " << line << ". Chi tiet: " << e.what() << endl;
        }
    }
    file.close();
}


void DataManager::loadKhachHang() {
    ifstream file(khFilename);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << khFilename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        try {
            if (!getline(ss, token, '/') || token != "KH") {
                cerr << "Loi dinh dang (Khong phai KH), bo qua: " << line << endl;
                continue;
            }

            KhachHang kh;
            string ma, ten, ns_d, ns_m, ns_y, sdt, cccd, gioiTinh, diaChi;
            string thuNhap_str, tongNo_str, diemUyTin_str;
            if (getline(ss, ma, '/')    && getline(ss, ten, '/')   &&
                getline(ss, ns_d, '/')  && getline(ss, ns_m, '/')  && getline(ss, ns_y, '/') &&
                getline(ss, sdt, '/')   && getline(ss, cccd, '/')  && getline(ss, gioiTinh, '/') &&
                getline(ss, diaChi, '/')&& getline(ss, thuNhap_str, '/') &&
                getline(ss, tongNo_str, '/') && getline(ss, diemUyTin_str, '/'))
            {
                kh.setMa(ma)
                  .setTen(ten)
                  .setNgaySinh(stoi(ns_d))
                  .setThangSinh(stoi(ns_m))
                  .setNamSinh(stoi(ns_y))
                  .setSdt(sdt)
                  .setCccd(cccd)
                  .setGioiTinh(gioiTinh)
                  .setDiaChi(diaChi)
                  .setThuNhap(stod(thuNhap_str))
                  .setTongNo(stod(tongNo_str))
                  .setDiemUyTin(stoi(diemUyTin_str));
                
                dsKhachHang.pushBack(kh);
            } else {
                cerr << "Loi dinh dang (Thieu truong KH), bo qua: " << line << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Loi khi doc dong trong " << khFilename << ": " << line << ". Chi tiet: " << e.what() << endl;
        }
    }
    file.close();
}

void DataManager::loadHopDongVay() {
    ifstream file(hdvFilename);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << hdvFilename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        try {
            if (!getline(ss, token, '/') || token != "HDV") {
                cerr << "Loi dinh dang (Khong phai HDV), bo qua: " << line << endl;
                continue;
            }

            HopDongVay hdv;
            string maHD, maKH, maNV, ngayVay, hanTra, trangThai, mucDich;
            string tienVay_str, laiSuat_str, thoiHan_str, theChap_str;
            if (getline(ss, maHD, '/')    && getline(ss, maKH, '/')  &&
                getline(ss, maNV, '/')    && getline(ss, tienVay_str, '/') &&
                getline(ss, laiSuat_str, '/') && getline(ss, ngayVay, '/') &&
                getline(ss, hanTra, '/')  && getline(ss, trangThai, '/') &&
                getline(ss, thoiHan_str, '/') && getline(ss, mucDich, '/') &&
                getline(ss, theChap_str, '/'))
            {
                hdv.setMaHopDong(maHD)
                   .setMaKhachHang(maKH)
                   .setMaNhanVien(maNV)
                   .setSoTienVay(stod(tienVay_str))
                   .setLaiSuat(stod(laiSuat_str))
                   .setNgayVay(ngayVay)
                   .setHanTra(hanTra)
                   .setTrangThai(trangThai)
                   .setThoiHan(stoi(thoiHan_str))
                   .setMucDich(mucDich)
                   .setGiaTriTheChap(stod(theChap_str));
                
                dsHopDongVay.pushBack(hdv);
            } else {
                cerr << "Loi dinh dang (Thieu truong HDV), bo qua: " << line << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Loi khi doc dong trong " << hdvFilename << ": " << line << ". Chi tiet: " << e.what() << endl;
        }
    }
    file.close();
}


void DataManager::loadTaiKhoan() {
    ifstream file(tkFilename);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << tkFilename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        try {
            if (!getline(ss, token, '/') || token != "TK") {
                cerr << "Loi dinh dang (Khong phai TK), bo qua: " << line << endl;
                continue;
            }

            TaiKhoan tk;
            string username, password, role, maLienKet;

            if (getline(ss, username, '/') && getline(ss, password, '/') &&
                getline(ss, role, '/')     && getline(ss, maLienKet, '/'))
            {
                tk.setUsername(username)
                  .setPassword(password)
                  .setRole(role)
                  .setMaLienKet(maLienKet);
                
                dsTaiKhoan.pushBack(tk);
            } else {
                cerr << "Loi dinh dang (Thieu truong TK), bo qua: " << line << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Loi khi doc dong trong " << tkFilename << ": " << line << ". Chi tiet: " << e.what() << endl;
        }
    }
    file.close();
}

void DataManager::loadThanhToan() {
    ifstream file(ttFilename);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << ttFilename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;

        try {
            if (!getline(ss, token, '/') || token != "TT") {
                cerr << "Loi dinh dang (Khong phai TT), bo qua: " << line << endl;
                continue;
            }

            ThanhToan tt;
            string maGD, maHD, ngayTT, tenGD, soTK, tenNH, hinhThuc, maNV;
            string soTien_str;

            if (getline(ss, maGD, '/')   && getline(ss, maHD, '/') &&
                getline(ss, soTien_str, '/') && getline(ss, ngayTT, '/') &&
                getline(ss, tenGD, '/')  && getline(ss, soTK, '/') &&
                getline(ss, tenNH, '/')  && getline(ss, hinhThuc, '/') &&
                getline(ss, maNV, '/'))
            {
                tt.setMaGiaoDich(maGD)
                  .setMaHopDong(maHD)
                  .setSoTienThanhToan(stod(soTien_str))
                  .setNgayThanhToan(ngayTT)
                  .setTenNguoiGiaoDich(tenGD)
                  .setSoTaiKhoan(soTK)
                  .setTenNganHang(tenNH)
                  .setHinhThucThanhToan(hinhThuc)
                  .setMaNhanVienXacNhan(maNV);
                
                dsThanhToan.pushBack(tt);
            } else {
                cerr << "Loi dinh dang (Thieu truong TT), bo qua: " << line << endl;
            }
        } catch (const std::exception& e) {
            cerr << "Loi khi doc dong trong " << ttFilename << ": " << line << ". Chi tiet: " << e.what() << endl;
        }
    }
    file.close();
}
void DataManager::saveNhanVien() {
    ofstream file(nvFilename);
    if (!file.is_open()) {
        cerr << "Khong the ghi file: " << nvFilename << endl;
        return;
    }
    dsNhanVien.saveToFile(file); //
    file.close();
}

void DataManager::saveKhachHang() {
    ofstream file(khFilename);
    if (!file.is_open()) {
        cerr << "Khong the ghi file: " << khFilename << endl;
        return;
    }
    dsKhachHang.saveToFile(file);
    file.close();
}

void DataManager::saveHopDongVay() {
    ofstream file(hdvFilename);
    if (!file.is_open()) {
        cerr << "Khong the ghi file: " << hdvFilename << endl;
        return;
    }
    dsHopDongVay.saveToFile(file);
    file.close();
}


void DataManager::saveTaiKhoan() {
    ofstream file(tkFilename);
    if (!file.is_open()) {
        cerr << "Khong the ghi file: " << tkFilename << endl;
        return;
    }
    dsTaiKhoan.saveToFile(file);
    file.close();
}
void DataManager::saveThanhToan() {
    ofstream file(ttFilename);
    if (!file.is_open()) {
        cerr << "Khong the ghi file: " << ttFilename << endl;
        return;
    }
    dsThanhToan.saveToFile(file); 
    file.close();
}
void DataManager::saveAllData() {
    cout << "Dang luu du lieu..." << endl;
    saveNhanVien();
    saveKhachHang();
    saveHopDongVay();
    saveTaiKhoan();
    saveThanhToan();
    cout << "Luu du lieu thanh cong!" << endl;
}
LinkedList<NhanVien>& DataManager::getNhanVienList() {
    return dsNhanVien;
}

LinkedList<KhachHang>& DataManager::getKhachHangList() {
    return dsKhachHang;
}

LinkedList<TaiKhoan>& DataManager::getTaiKhoanList() {
    return dsTaiKhoan;
}

LinkedList<HopDongVay>& DataManager::getHopDongVayList() {
    return dsHopDongVay;
}

LinkedList<ThanhToan>& DataManager::getThanhToanList() {
    return dsThanhToan;
}
