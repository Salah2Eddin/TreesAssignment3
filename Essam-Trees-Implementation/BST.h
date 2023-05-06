#pragma once
#include <bits/stdc++.h>
#include "Student.h"


class BST {

// --------------Node----------------
    class Node{
    public:
        Node* rChild = NULL;
        Student value;
        Node* lChild = NULL;
    public:
        Node() = default;
    };

// --------------Main Menu----------------
private:
    std::map<std::string,int>freqDepartment;
public:
    void addStudent(Student& student);
    void removeStudent(Student& student);
    void printAllStudents();

// --------------BST Tree----------------
private:
    Node* root = NULL;
    int cnt = 0;
public:
    Node * InsertRec(Node* p, Student student);
    void InsertItr(Student student);
    Node * Delete(Node* p,Student student);
    bool Search(Student student);
    void Print(Node* p);
    int Height(Node* p);
    Node * InPre(Node* p);
    Node * InSucc(Node* p);
};


