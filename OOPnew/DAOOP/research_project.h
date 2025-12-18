#ifndef RESEARCH_PROJECT_H
#define RESEARCH_PROJECT_H

#include <iostream>
#include <string>
#include "exceptions.h"

class ResearchProject {
protected:
    std::string id;
    std::string title;
    std::string author;
    int year;

public:
    ResearchProject(const std::string& id, const std::string& title, 
                   const std::string& author, int year)
        : id(id), title(title), author(author), year(year) {
        validateYear(year);
    }

    virtual ~ResearchProject() {}

    // Getter methods
    std::string getId() const { return id; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    int getYear() const { return year; }

    // Pure virtual function
    virtual void display() const = 0;
    virtual std::string getType() const = 0;

    // Validation
    static void validateYear(int year) {
        if (year < 2000 || year > 2025) {
            throw InvalidYearException(year);
        }
    }

    // Virtual function for file output
    virtual std::string toFileString() const = 0;
};

class JournalPaper : public ResearchProject {
private:
    std::string journalName;
    double impactFactor;

public:
    JournalPaper(const std::string& id, const std::string& title,
                const std::string& author, int year,
                const std::string& journalName, double impactFactor)
        : ResearchProject(id, title, author, year),
          journalName(journalName), impactFactor(impactFactor) {
        if (impactFactor < 0) {
            throw InvalidValueException("chỉ số ảnh hưởng");
        }
    }

    void display() const override {
        std::cout << "=== Bài Báo Tạp Chí ===" << std::endl;
        std::cout << "Mã: " << id << std::endl;
        std::cout << "Tiêu đề: " << title << std::endl;
        std::cout << "Tác giả: " << author << std::endl;
        std::cout << "Năm: " << year << std::endl;
        std::cout << "Tên tạp chí: " << journalName << std::endl;
        std::cout << "Chỉ số ảnh hưởng: " << impactFactor << std::endl;
        std::cout << "=======================" << std::endl;
    }

    std::string getType() const override {
        return "JournalPaper";
    }

    std::string toFileString() const override {
        return getType() + "|" + id + "|" + title + "|" + author + "|" +
               std::to_string(year) + "|" + journalName + "|" +
               std::to_string(impactFactor);
    }
};

class ConferencePaper : public ResearchProject {
private:
    std::string conferenceName;
    std::string location;

public:
    ConferencePaper(const std::string& id, const std::string& title,
                   const std::string& author, int year,
                   const std::string& conferenceName, const std::string& location)
        : ResearchProject(id, title, author, year),
          conferenceName(conferenceName), location(location) {}

    void display() const override {
        std::cout << "=== Bài Báo Hội Nghị ===" << std::endl;
        std::cout << "Mã: " << id << std::endl;
        std::cout << "Tiêu đề: " << title << std::endl;
        std::cout << "Tác giả: " << author << std::endl;
        std::cout << "Năm: " << year << std::endl;
        std::cout << "Tên hội nghị: " << conferenceName << std::endl;
        std::cout << "Địa điểm: " << location << std::endl;
        std::cout << "========================" << std::endl;
    }

    std::string getType() const override {
        return "ConferencePaper";
    }

    std::string toFileString() const override {
        return getType() + "|" + id + "|" + title + "|" + author + "|" +
               std::to_string(year) + "|" + conferenceName + "|" + location;
    }
};

class ResearchGrant : public ResearchProject {
private:
    double budget;
    int duration;

public:
    ResearchGrant(const std::string& id, const std::string& title,
                 const std::string& author, int year,
                 double budget, int duration)
        : ResearchProject(id, title, author, year),
          budget(budget), duration(duration) {
        if (budget < 0) {
            throw InvalidValueException("kinh phí");
        }
        if (duration < 0) {
            throw InvalidValueException("thời gian");
        }
    }

    void display() const override {
        std::cout << "=== Đề Tài Nghiên Cứu ===" << std::endl;
        std::cout << "Mã: " << id << std::endl;
        std::cout << "Tiêu đề: " << title << std::endl;
        std::cout << "Tác giả: " << author << std::endl;
        std::cout << "Năm: " << year << std::endl;
        std::cout << "Kinh phí: " << budget << " triệu đồng" << std::endl;
        std::cout << "Thời gian: " << duration << " tháng" << std::endl;
        std::cout << "=========================" << std::endl;
    }

    std::string getType() const override {
        return "ResearchGrant";
    }

    double getBudget() const { return budget; }
    int getDuration() const { return duration; }

    std::string toFileString() const override {
        return getType() + "|" + id + "|" + title + "|" + author + "|" +
               std::to_string(year) + "|" + std::to_string(budget) + "|" +
               std::to_string(duration);
    }
};

#endif