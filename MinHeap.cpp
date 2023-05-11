#include "MinHeap.h"

void MinHeap::addStudent(Student student) {
    students.push_back(student);
    int stSize = students.size();
    for(int i = stSize / 2; i >= 0; --i){
        heapify(i,stSize);
    }
}

void MinHeap::printAllStudents() {
    heapSort();
    for(auto st : students){
        std::cout << st << std::endl;
    }
}

void MinHeap::heapify(int idx, int stSize) {
    int smallestChildIdx = idx;
    int leftChildIdx = 2 * idx;
    int rightChildIdx = 2 * idx + 1;
    if(leftChildIdx < stSize
        && students[leftChildIdx].compareByGpa(students[smallestChildIdx])){
        smallestChildIdx = leftChildIdx;

    }
    if(rightChildIdx < stSize
    && students[rightChildIdx].compareByGpa(students[smallestChildIdx])){
        smallestChildIdx = rightChildIdx;
    }
    if(smallestChildIdx != idx){
        std::swap(students[smallestChildIdx], students[idx]);
        heapify(smallestChildIdx, stSize);
    }

}

void MinHeap::heapSort() {
    int stSize = students.size();
    for(int i = stSize - 1; i >= 0; --i){
        std::swap(students[0], students[i]);
        heapify(0,i);
    }
    for(int i = 0; i < stSize/2; ++i){
        std::swap(students[i], students[stSize-1-i]);
    }
}

bool MinHeap::search(const Student& stud) {
    for(auto stud2 : students){
        if(stud2.getId() == stud.getId()){
            return true;
        }
    }
    return false;
}
