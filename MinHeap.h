#pragma once
#include "vector"
#include "Student.h"


class MinHeap{
private:
    std::vector<Student>students;
public:
    void heapify(int idx, int stSize);
    void heapSort();
    bool search(const Student& stud);
    void addStudent(Student student);
    void printAllStudents();
};



