#pragma once
#include "vector"
#include "Student.cpp"


class MinHeap{
private:
    std::vector<Student>students;
public:
    void heapify(int idx, int stSize);
    void heapSort();
    void addStudent(Student student);
    void printAllStudents();
};



