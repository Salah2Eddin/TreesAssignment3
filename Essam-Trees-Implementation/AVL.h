#pragma once
#include <bits/stdc++.h>
#include "Student.h"


class AVL {

// --------------Node----------------
    class Node{
    public:
        Node* rChild = NULL;
        Student value;
        int height = 0;
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


// --------------AVL Tree----------------
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
    int BalanceFactor(Node* p);
    Node * InPre(Node* p);
    Node * InSucc(Node* p);

public:
    Node * leftRotation(Node* p);
    Node * leftRightRotation(Node* p);
    Node * rightRotation(Node* p);
    Node * rightLeftRotation(Node* p);
};


