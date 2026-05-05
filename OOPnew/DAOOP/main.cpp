#include <iostream>
#include <limits>
#include "research_manager.h"

void displayMenu() {
    std::cout << "\n=========== HỆ THỐNG QUẢN LÝ CÔNG TRÌNH NGHIÊN CỨU ===========" << std::endl;
    std::cout << "1. Thêm công trình mới" << std::endl;
    std::cout << "2. Xóa công trình theo ID" << std::endl;
    std::cout << "3. Tìm kiếm công trình theo ID" << std::endl;
    std::cout << "4. Hiển thị toàn bộ công trình" << std::endl;
    std::cout << "5. Thống kê" << std::endl;
    std::cout << "6. Sắp xếp theo năm" << std::endl;
    std::cout << "7. Sắp xếp theo tác giả" << std::endl;
    std::cout << "8. Lưu dữ liệu" << std::endl;
    std::cout << "9. Thoát" << std::endl;
    std::cout << "=============================================================" << std::endl;
    std::cout << "Chọn chức năng (1-9): ";
}

ResearchProject* createProject() {
    std::string id, title, author;
    int year;

    std::cout << "Nhập mã công trình: ";
    std::cin.ignore();
    std::getline(std::cin, id);

    std::cout << "Nhập tên công trình: ";
    std::getline(std::cin, title);

    std::cout << "Nhập tên tác giả chính: ";
    std::getline(std::cin, author);

    std::cout << "Nhập năm (2000-2025): ";
    std::cin >> year;

    std::cout << "Chọn loại công trình:" << std::endl;
    std::cout << "1. Bài báo tạp chí" << std::endl;
    std::cout << "2. Bài báo hội nghị" << std::endl;
    std::cout << "3. Đề tài nghiên cứu" << std::endl;
    std::cout << "Chọn (1-3): ";

    int type;
    std::cin >> type;

    try {
        switch (type) {
            case 1: {
                std::string journalName;
                double impactFactor;
                
                std::cout << "Nhập tên tạp chí: ";
                std::cin.ignore();
                std::getline(std::cin, journalName);
                
                std::cout << "Nhập chỉ số ảnh hưởng: ";
                std::cin >> impactFactor;
                
                return new JournalPaper(id, title, author, year, journalName, impactFactor);
            }
            case 2: {
                std::string conferenceName, location;
                
                std::cout << "Nhập tên hội nghị: ";
                std::cin.ignore();
                std::getline(std::cin, conferenceName);
                
                std::cout << "Nhập địa điểm: ";
                std::getline(std::cin, location);
                
                return new ConferencePaper(id, title, author, year, conferenceName, location);
            }
            case 3: {
                double budget;
                int duration;
                
                std::cout << "Nhập kinh phí (triệu đồng): ";
                std::cin >> budget;
                
                std::cout << "Nhập thời gian (tháng): ";
                std::cin >> duration;
                
                return new ResearchGrant(id, title, author, year, budget, duration);
            }
            default:
                std::cout << "Lựa chọn không hợp lệ!" << std::endl;
                return nullptr;
        }
    }
    catch (const std::exception& e) {
        std::cout << "Lỗi: " << e.what() << std::endl;
        return nullptr;
    }
}

int main() {
    ResearchManager manager;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1: {
                ResearchProject* project = createProject();
                if (project != nullptr) {
                    try {
                        manager.addProject(project);
                    }
                    catch (const std::exception& e) {
                        std::cout << "Lỗi: " << e.what() << std::endl;
                        delete project;
                    }
                }
                break;
            }
            case 2: {
                std::string id;
                std::cout << "Nhập ID cần xóa: ";
                std::cin.ignore();
                std::getline(std::cin, id);
                manager.removeProject(id);
                break;
            }
            case 3: {
                std::string id;
                std::cout << "Nhập ID cần tìm: ";
                std::cin.ignore();
                std::getline(std::cin, id);
                manager.findProject(id);
                break;
            }
            case 4:
                manager.displayAllProjects();
                break;
            case 5:
                manager.displayStatistics();
                break;
            case 6:
                manager.sortByYear();
                break;
            case 7:
                manager.sortByAuthor();
                break;
            case 8:
                manager.saveToFile();
                break;
            case 9:
                std::cout << "Cảm ơn đã sử dụng chương trình!" << std::endl;
                break;
            default:
                std::cout << "Lựa chọn không hợp lệ! Vui lòng chọn lại." << std::endl;
                break;
        }

        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 9);

    return 0;
}