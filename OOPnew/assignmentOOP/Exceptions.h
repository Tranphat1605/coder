#include <exception>

class DuplicateIDException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Duplicated ID!";
    }
};

class InvalidYearException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Nam khong hop le (2000 - 2025)";
    }
};

class InvalidValueException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Gia tri so khong hop le!";
    }
};
