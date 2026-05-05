#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(T d) : data(d), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node<T>* p;
        while (head) {
            p = head;
            head = head->next;
            delete p;
        }
    }

    void add(T x) {
        Node<T>* p = new Node<T>(x);
        p->next = head;
        head = p;
    }

    bool removeByID(const string& id) {
        Node<T>* cur = head;
        Node<T>* prev = nullptr;

        while (cur) {
            if (cur->data->getID() == id) {
                if (prev) prev->next = cur->next;
                else head = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
        }
        return false;
    }

    T findByID(const string& id) {
        Node<T>* cur = head;
        while (cur) {
            if (cur->data->getID() == id)
                return cur->data;
            cur = cur->next;
        }
        return nullptr;
    }

    void displayAll() const {
        Node<T>* cur = head;
        while (cur) {
            cur->data->display();
            cout << "-----------------------\n";
            cur = cur->next;
        }
    }

    vector<T> toVector() const {
        vector<T> v;
        Node<T>* cur = head;
        while (cur) {
            v.push_back(cur->data);
            cur = cur->next;
        }
        return v;
    }
};
