#include "MaxHeap.h"

void MaxHeap::addStudent(Student student) {
    students.push_back(student);
    int stSize = students.size();
    for(int i = stSize / 2 - 1; i >= 0; --i){
        heapify(i,stSize);
    }
}

void MaxHeap::printAllStudents() {
    heapSort();
    for(auto st : students){
        std::cout << st << std::endl;
    }
}

void MaxHeap::heapify(int idx, int stSize) {
    int largestChildIdx = idx;
    int leftChildIdx = 2 * idx + 1;
    int rightChildIdx = 2 * idx + 2;
    if(leftChildIdx < stSize
       && students[largestChildIdx].compareByGpa(students[leftChildIdx])){
        largestChildIdx = leftChildIdx;

    }
    if(rightChildIdx < stSize
       && students[largestChildIdx].compareByGpa(students[rightChildIdx])){
        largestChildIdx = rightChildIdx;
    }
    if(largestChildIdx != idx){
        std::swap(students[largestChildIdx], students[idx]);
        heapify(largestChildIdx, stSize);
    }

}

void MaxHeap::heapSort() {
    int stSize = students.size();
    for(int i = stSize - 1; i >= 0; --i){
        std::swap(students[0], students[i]);
        heapify(0,i);
    }
}