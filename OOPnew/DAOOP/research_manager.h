#ifndef RESEARCH_MANAGER_H
#define RESEARCH_MANAGER_H

#include "linked_list.h"
#include <fstream>
#include <sstream>
#include <algorithm>

class ResearchManager {
private:
    LinkedList<ResearchProject*> projects;

    // Statistics
    struct Statistics {
        int journalCount = 0;
        int conferenceCount = 0;
        int grantCount = 0;
        double totalBudget = 0;
        int totalDuration = 0;
    };

public:
    ResearchManager() {
        loadFromFile();
    }

    ~ResearchManager() {
        saveToFile();
    }

    void addProject(ResearchProject* project) {
        // Check for duplicate ID
        if (projects.find(project->getId()) != nullptr) {
            delete project;
            throw DuplicateIDException(project->getId());
        }
        
        projects.add(project);
        std::cout << "Thêm công trình thành công!" << std::endl;
    }

    void removeProject(const std::string& id) {
        if (projects.remove(id)) {
            std::cout << "Đã xóa công trình với mã '" << id << "' thành công!" << std::endl;
        } else {
            std::cout << "Không tìm thấy công trình với mã '" << id << "'!" << std::endl;
        }
    }

    void findProject(const std::string& id) const {
        ResearchProject* project = projects.find(id);
        if (project != nullptr) {
            project->display();
        } else {
            std::cout << "Không tìm thấy công trình với mã '" << id << "'!" << std::endl;
        }
    }

    void displayAllProjects() const {
        projects.displayAll();
    }

    void displayStatistics() const {
        Statistics stats;
        Node<ResearchProject*>* current = projects.getHead();
        
        while (current != nullptr) {
            std::string type = current->data->getType();
            
            if (type == "JournalPaper") {
                stats.journalCount++;
            } else if (type == "ConferencePaper") {
                stats.conferenceCount++;
            } else if (type == "ResearchGrant") {
                stats.grantCount++;
                ResearchGrant* grant = dynamic_cast<ResearchGrant*>(current->data);
                if (grant) {
                    stats.totalBudget += grant->getBudget();
                    stats.totalDuration += grant->getDuration();
                }
            }
            current = current->next;
        }

        std::cout << "=== THỐNG KÊ ===" << std::endl;
        std::cout << "Tổng số công trình: " << projects.getSize() << std::endl;
        std::cout << "Bài báo tạp chí: " << stats.journalCount << std::endl;
        std::cout << "Bài báo hội nghị: " << stats.conferenceCount << std::endl;
        std::cout << "Đề tài nghiên cứu: " << stats.grantCount << std::endl;
        std::cout << "Tổng kinh phí: " << stats.totalBudget << " triệu đồng" << std::endl;
        std::cout << "Tổng thời gian: " << stats.totalDuration << " tháng" << std::endl;
        std::cout << "=================" << std::endl;
    }

    void sortByYear() {
        // Convert linked list to vector for sorting
        std::vector<ResearchProject*> projectList;
        Node<ResearchProject*>* current = projects.getHead();
        
        while (current != nullptr) {
            projectList.push_back(current->data);
            current = current->next;
        }

        // Sort by year
        std::sort(projectList.begin(), projectList.end(),
            [](ResearchProject* a, ResearchProject* b) {
                return a->getYear() < b->getYear();
            });

        // Rebuild linked list
        projects.clear();
        for (ResearchProject* project : projectList) {
            projects.add(project);
        }

        std::cout << "Đã sắp xếp công trình theo năm!" << std::endl;
    }

    void sortByAuthor() {
        // Convert linked list to vector for sorting
        std::vector<ResearchProject*> projectList;
        Node<ResearchProject*>* current = projects.getHead();
        
        while (current != nullptr) {
            projectList.push_back(current->data);
            current = current->next;
        }

        // Sort by author
        std::sort(projectList.begin(), projectList.end(),
            [](ResearchProject* a, ResearchProject* b) {
                return a->getAuthor() < b->getAuthor();
            });

        // Rebuild linked list
        projects.clear();
        for (ResearchProject* project : projectList) {
            projects.add(project);
        }

        std::cout << "Đã sắp xếp công trình theo tác giả!" << std::endl;
    }

    void saveToFile() const {
        std::ofstream file("research.txt");
        if (!file.is_open()) {
            std::cout << "Lỗi: Không thể mở file để ghi!" << std::endl;
            return;
        }

        Node<ResearchProject*>* current = projects.getHead();
        while (current != nullptr) {
            file << current->data->toFileString() << std::endl;
            current = current->next;
        }

        file.close();
        std::cout << "Đã lưu dữ liệu vào research.txt" << std::endl;
    }

    void loadFromFile() {
        std::ifstream file("research.txt");
        if (!file.is_open()) {
            std::cout << "Không tìm thấy file dữ liệu. Bắt đầu với cơ sở dữ liệu trống." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string token;
            std::vector<std::string> tokens;

            while (std::getline(ss, token, '|')) {
                tokens.push_back(token);
            }

            if (tokens.size() < 5) continue;

            try {
                std::string type = tokens[0];
                std::string id = tokens[1];
                std::string title = tokens[2];
                std::string author = tokens[3];
                int year = std::stoi(tokens[4]);

                ResearchProject* project = nullptr;

                if (type == "JournalPaper" && tokens.size() >= 7) {
                    std::string journalName = tokens[5];
                    double impactFactor = std::stod(tokens[6]);
                    project = new JournalPaper(id, title, author, year, journalName, impactFactor);
                }
                else if (type == "ConferencePaper" && tokens.size() >= 7) {
                    std::string conferenceName = tokens[5];
                    std::string location = tokens[6];
                    project = new ConferencePaper(id, title, author, year, conferenceName, location);
                }
                else if (type == "ResearchGrant" && tokens.size() >= 7) {
                    double budget = std::stod(tokens[5]);
                    int duration = std::stoi(tokens[6]);
                    project = new ResearchGrant(id, title, author, year, budget, duration);
                }

                if (project != nullptr) {
                    projects.add(project);
                }
            }
            catch (const std::exception& e) {
                std::cout << "Lỗi khi tải công trình: " << e.what() << std::endl;
            }
        }

        file.close();
        std::cout << "Đã tải dữ liệu từ research.txt" << std::endl;
    }
};

#endif