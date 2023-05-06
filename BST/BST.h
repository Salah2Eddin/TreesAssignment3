#ifndef DATASTRUCTURES_BST_H
#define DATASTRUCTURES_BST_H

#include <iostream>
#include <map>
#include "Student.h"

struct Node {
    Node *lChild = nullptr;
    Node *rChild = nullptr;
    Student student;
    explicit Node(const Student& student) : student(student) {}
};

class BST {
private:
    Node *root = nullptr;
    int size = 0;
public:
    ~BST();
    void insert(Student student);
    Node *remove(Node *root, int id);
    Node *search(int id);
    void print(Node *current);
    void getNumStudentsDepartment(Node *current, std::map<std::string, int> &departments);
    void printNumStudentsDepartment(Node *current, std::map<std::string, int> &departments);
    int getSize();
    Node *getRoot();
    void setRoot(Node *root);

    Node *findMin(Node *pNode);
};


#endif //DATASTRUCTURES_BST_H
