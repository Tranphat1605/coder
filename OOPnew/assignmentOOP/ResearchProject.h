#include <iostream>
#include <string>
using namespace std;

class ResearchProject {
protected:
    string id;
    string title;
    string author;
    int year;

public:
    ResearchProject(const string& id, const string& title, const string& author, int year)
        : id(id), title(title), author(author), year(year) {}
    virtual ~ResearchProject() {}
    string getID() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    virtual void display() const = 0;
};

class JournalPaper : public ResearchProject {
private:
    string journalName;
    double impactFactor;

public:
    JournalPaper(const string& id, const string& title, const string& author, int year, const string& journalName, double impactFactor)
        : ResearchProject(id, title, author, year),  journalName(journalName),  impactFactor(impactFactor) {}

    string getJournalName() const { return journalName; }
    double getImpactFactor() const { return impactFactor; }
    void display() const override {
        cout << "[Bai bao tap chi]\n";
        cout << "ID: " << id << "\nTen: " << title << "\n";
        cout << "Tac gia: " << author << "\nNam: " << year << "\n";
        cout << "Tap chi: " << journalName
             << "\nImpact Factor: " << impactFactor << "\n";
    }
};

class ConferencePaper : public ResearchProject {
private:
    string conferenceName;
    string location;

public:
    ConferencePaper(const string& id, const string& title, const string& author, int year, const string& conferenceName, const string& location)
        : ResearchProject(id, title, author, year), conferenceName(conferenceName), location(location) {}
    string getConferenceName() const { return conferenceName; }
    string getLocation() const { return location; }
    void display() const override {
        cout << "[Bai bao hoi nghi]\n";
        cout << "ID: " << id << "\nTen: " << title << "\n";
        cout << "Tac gia: " << author << "\nNam: " << year << "\n";
        cout << "Hoi nghi: " << conferenceName
             << "\nDia diem: " << location << "\n";
    }
};

class ResearchGrant : public ResearchProject {
private:
    double budget;
    int duration;

public:
    ResearchGrant(const string& id, const string& title, const string& author, int year, double budget, int duration)
        : ResearchProject(id, title, author, year), budget(budget), duration(duration) {}
    double getBudget() const { return budget; }
    int getDuration() const { return duration; }

    void display() const override {
        cout << "[De tai nghien cuu]\n";
        cout << "ID: " << id << "\nTen: " << title << "\n";
        cout << "Tac gia: " << author << "\nNam: " << year << "\n";
        cout << "Kinh phi: " << budget << " trieu dong\n";
        cout << "Thoi gian: " << duration << " thang\n";
    }
};
