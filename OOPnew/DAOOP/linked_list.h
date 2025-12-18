#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "research_project.h"

template<typename T>
class Node {
public:
    T data;
    Node* next;
    
    Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void add(T data) {
        Node<T>* newNode = new Node<T>(data);
        
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    bool remove(const std::string& id) {
        if (head == nullptr) return false;

        // Check if head needs to be removed
        if (head->data->getId() == id) {
            Node<T>* temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
            size--;
            return true;
        }

        // Search for node to remove
        Node<T>* current = head;
        while (current->next != nullptr) {
            if (current->next->data->getId() == id) {
                Node<T>* temp = current->next;
                current->next = temp->next;
                delete temp->data;
                delete temp;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    T find(const std::string& id) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data->getId() == id) {
                return current->data;
            }
            current = current->next;
        }
        return nullptr;
    }

    void displayAll() const {
        if (head == nullptr) {
            std::cout << "Không tìm thấy công trình nào." << std::endl;
            return;
        }

        Node<T>* current = head;
        int count = 1;
        while (current != nullptr) {
            std::cout << "Công trình " << count << ":" << std::endl;
            current->data->display();
            current = current->next;
            count++;
        }
    }

    int getSize() const {
        return size;
    }

    void clear() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp->data;
            delete temp;
        }
        size = 0;
    }

    // Iterator support for advanced operations
    Node<T>* getHead() const {
        return head;
    }
};

#endif