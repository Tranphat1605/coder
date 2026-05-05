#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class DuplicateIDException : public std::exception {
private:
    std::string message;
public:
    DuplicateIDException(const std::string& id) {
        message = "Mã ID bị trùng: " + id;
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidYearException : public std::exception {
private:
    std::string message;
public:
    InvalidYearException(int year) {
        message = "Năm không hợp lệ: " + std::to_string(year) + " (phải từ 2000-2025)";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidValueException : public std::exception {
private:
    std::string message;
public:
    InvalidValueException(const std::string& field) {
        message = "Giá trị không hợp lệ cho: " + field + " (phải là số dương)";
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif