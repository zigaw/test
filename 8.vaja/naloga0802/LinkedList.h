#ifndef NALOGA0802_LINKEDLIST_H
#define NALOGA0802_LINKEDLIST_H

#include <iostream>

template<typename T>
class Node {
private:
    T value;
    Node<T>* next;
public:
    Node(T value, Node<T>* next = nullptr) : value(value), next(next) {}

    T getValue() const {
        return value;
    }

    void setValue(T value) {
        this->value = value;
    }

    Node<T>* getNext() const {
        return next;
    }

    void setNext(Node<T>* next) {
        this->next = next;
    }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head = nullptr;
public:
    bool isEmpty() const {
        if (head == nullptr) {
            return true;
        }
        return false;
    }

    int getSize() const {
        int counter = 0;
        Node<T>* current = head;
        while(current != nullptr){
            counter++;
            current = current->getNext();
        }
        return counter;
    }

    void add(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    }

    T at(unsigned int index) {
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            if (current == nullptr) {
                throw std::out_of_range("Index out of range");
            }
            current = current->getNext();
        }
        if (current == nullptr) {
            throw std::out_of_range("Index out of range");
        }
        return current->getValue();
    }

    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* temp;
        while(current != nullptr){
            temp = current;
            current = current->getNext();
            delete temp;
        }
    }

    void insertAt(T value,unsigned int index) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *prev;
        Node<T> *current = head;
        if(index == 0){
            newNode->setNext(current);
            head = newNode;
        }else {
            for (int i = 1; i <= index; ++i) {

                if (current == nullptr) {
                    throw std::out_of_range("Index out of range");
                }


                    prev = current;
                    current = current->getNext();


                if (current == nullptr) {
                    throw std::out_of_range("Index out of range");
                }

                if (i == index) {
                    prev->setNext(newNode);
                    newNode->setNext(current->getNext());
                    current = newNode;
                }
            }
        }
    }
};

#endif //NALOGA0802_LINKEDLIST_H
