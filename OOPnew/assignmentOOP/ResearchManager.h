#pragma once
#include "ResearchProject.h"
#include "LinkedList.h"
#include "Exceptions.h"
#include <fstream>
#include <vector>
#include <sstream>

class ResearchManager {
private:
    LinkedList<ResearchProject*> ds;
    void quickSortYear(vector<ResearchProject*>& arr, int left, int right) {
        if (left < right) {
            int pivotIndex = partitionYear(arr, left, right);
            quickSortYear(arr, left, pivotIndex - 1);
            quickSortYear(arr, pivotIndex + 1, right);
        }
    }

    int partitionYear(vector<ResearchProject*>& arr, int left, int right) {
        int pivotYear = arr[right]->getYear();
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j]->getYear() < pivotYear) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        return i + 1;
    }

    void quickSortAuthor(vector<ResearchProject*>& arr, int left, int right) {
        if (left < right) {
            int pivotIndex = partitionAuthor(arr, left, right);
            quickSortAuthor(arr, left, pivotIndex - 1);
            quickSortAuthor(arr, pivotIndex + 1, right);
        }
    }

    int partitionAuthor(vector<ResearchProject*>& arr, int left, int right) {
        string pivotAuthor = arr[right]->getAuthor();
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (arr[j]->getAuthor() < pivotAuthor) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[right]);
        return i + 1;
    }

    void swap(ResearchProject*& a, ResearchProject*& b) {
        ResearchProject* temp = a;
        a = b;
        b = temp;
    }
    void capNhatFile() {
        ghiFile();
    }

public:
    ResearchManager() {
        docFile();
    }

    ~ResearchManager() {
        ghiFile();
    }

    void themCongTrinh(ResearchProject* p) {
        if (ds.findByID(p->getID()) != nullptr)
            throw DuplicateIDException();

        if (p->getYear() < 2000 || p->getYear() > 2025)
            throw InvalidYearException();
        if (auto jp = dynamic_cast<JournalPaper*>(p)) {
            if (jp->getImpactFactor() < 0)
                throw InvalidValueException();
        }
        else if (auto rg = dynamic_cast<ResearchGrant*>(p)) {
            if (rg->getBudget() < 0 || rg->getDuration() < 0)
                throw InvalidValueException();
        }
        ds.add(p);
        capNhatFile();
        cout << "Them thanh cong va da cap nhat file!\n";
    }

    void xoaCongTrinh(const string& id) {
        if (!ds.removeByID(id)) {
            cout << "Khong tim thay cong trinh!\n";
        } else {
            cout << "Xoa thanh cong va da cap nhat file!\n";
            capNhatFile();
        }
    }

    void timCongTrinh(const string& id) {
        ResearchProject* p = ds.findByID(id);
        if (p) p->display();
        else cout << "Khong tim thay!\n";
    }

    void hienThiTatCa() {
        ds.displayAll();
    }

    void ghiFile() {
        ofstream out("research.txt");
        if (!out) {
            cout << "Loi mo file de ghi!\n";
            return;
        }

        auto v = ds.toVector();
        for (auto p : v) {
            if (auto jp = dynamic_cast<JournalPaper*>(p)) {
                out << "J|" << jp->getID() << "|" << jp->getTitle() << "|" 
                    << jp->getAuthor() << "|" << jp->getYear() << "|"
                    << jp->getJournalName() << "|" << jp->getImpactFactor() << "\n";
            }
            else if (auto cp = dynamic_cast<ConferencePaper*>(p)) {
                out << "C|" << cp->getID() << "|" << cp->getTitle() << "|"
                    << cp->getAuthor() << "|" << cp->getYear() << "|"
                    << cp->getConferenceName() << "|" << cp->getLocation() << "\n";
            }
            else if (auto rg = dynamic_cast<ResearchGrant*>(p)) {
                out << "G|" << rg->getID() << "|" << rg->getTitle() << "|"
                    << rg->getAuthor() << "|" << rg->getYear() << "|"
                    << rg->getBudget() << "|" << rg->getDuration() << "\n";
            }
        }
        out.close();
    }
    void docFile() {
    ifstream in("research.txt");
    if (!in) {
        cout << "Khong tim thay file du lieu. Tao moi...\n";
        return;
    }

    string line;
    int lineNum = 0;
    int success = 0, skipped = 0;

    while (getline(in, line)) {
        lineNum++;
        if (line.empty() || line[0] == '#') continue;
        istringstream ss(line);
        string loai;
        if (!getline(ss, loai, '|')) continue;
        try {
            string id, ten, tacGia, namStr, f4, f5;
            if (!getline(ss, id, '|') || !getline(ss, ten, '|') ||
                !getline(ss, tacGia, '|') || !getline(ss, namStr, '|') ||
                !getline(ss, f4, '|') || !(ss >> f5)) {
                throw runtime_error("Du lieu khong du truong");
            }
            int nam = stoi(namStr);
            ResearchProject* p = nullptr;
            if (loai == "J") {
                p = new JournalPaper(id, ten, tacGia, nam, f4, stod(f5));
            }
            else if (loai == "C") {
                p = new ConferencePaper(id, ten, tacGia, nam, f4, f5);
            }
            else if (loai == "G") {
                p = new ResearchGrant(id, ten, tacGia, nam, stod(f4), stoi(f5));
            }
            else {
                throw runtime_error("Loai cong trinh khong hop le");
            }
            themCongTrinh(p);
            success++;
        }
        catch (const exception& e) {
            cout << "BO QUA DONG " << lineNum << " (loi): " << e.what() << endl;
            skipped++;
        }
    }
    in.close();
    cout << "Da tai du lieu tu file: " << success << " thanh cong, " << skipped << " bi bo qua.\n";
}

    void thongKe() {
        auto v = ds.toVector();

        int j = 0, c = 0, g = 0;
        double totalBudget = 0;
        int totalDuration = 0;

        for (auto p : v) {
            if (dynamic_cast<JournalPaper*>(p)) j++;
            else if (dynamic_cast<ConferencePaper*>(p)) c++;
            else if (auto rg = dynamic_cast<ResearchGrant*>(p)) {
                g++;
                totalBudget += rg->getBudget();
                totalDuration += rg->getDuration();
            }
        }

        cout << "===== THONG KE =====\n";
        cout << "Journal Paper: " << j << "\n";
        cout << "Conference Paper: " << c << "\n";
        cout << "Research Grant: " << g << "\n";
        cout << "Tong kinh phi Grant: " << totalBudget << " trieu dong\n";
        cout << "Tong thoi gian Grant: " << totalDuration << " thang\n";
    }

    void sapXepTheoNam() {
        auto v = ds.toVector();
        if (!v.empty()) {
            quickSortYear(v, 0, v.size() - 1);
        }

        cout << "===== SAP XEP THEO NAM =====\n";
        for (auto p : v) {
            p->display();
            cout << "-------------------\n";
        }
    }

    void sapXepTheoTacGia() {
        auto v = ds.toVector();
        if (!v.empty()) {
            quickSortAuthor(v, 0, v.size() - 1);
        }

        cout << "===== SAP XEP THEO TAC GIA =====\n";
        for (auto p : v) {
            p->display();
            cout << "-------------------\n";
        }
    }
};