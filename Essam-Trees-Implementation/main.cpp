#include "MinHeap.cpp"
#include "MaxHeap.cpp"
#include "BST.cpp"
#include "AVL.cpp"
using namespace std;

int main() {
    AVL minHeap;
    Student st1("Mohamed","IS",3.0);
    Student st3("Salah","AI",4.0);
    Student st2("Maya","CS",2.0);
    Student st4("Ahmed","DS",5.0);
    Student st5("Ahmed","DS",6.0);
    Student st6("Omar","AI",3.0);
    minHeap.addStudent(st1);
    minHeap.addStudent(st4);
    minHeap.addStudent(st2);
    minHeap.addStudent(st3);
    minHeap.addStudent(st5);
    minHeap.Search(st6);
    minHeap.removeStudent(st6);
    minHeap.printAllStudents();
}
