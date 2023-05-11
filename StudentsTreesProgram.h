#pragma once

#include <fstream>
#include "Student.h"
#include "BST.h"
#include "AVL.h"
#include "MaxHeap.h"
#include "MinHeap.h"

#include <map>

class Program {
private:
    BST bst;
    AVL<int, Student> avl;
    MinHeap mnHeap;
    MaxHeap mxHeap;


public:
    Program() {
        std::ifstream fs("students.txt");
        int n;
        fs >> n;
        for (int i = 0; i < n; ++i) {
            std::string name, dep;
            double gpa;
            int id;
            fs >> id;

            fs.ignore();
            std::getline(fs, name);

            fs >> gpa >> dep;
            Student stud = Student(id, name, dep, gpa);

            bst.insert(stud);
            avl.insert(id, stud);
            mnHeap.addStudent(stud);
            mxHeap.addStudent(stud);
        }
        fs.close();
    }

    void mainLoop() {
        while (true) {
            printMainMenu();
            int input = takeUserInput();
            switch (input) {
                case 1: {
                    BSTMenu();
                    break;
                }
                case 2: {
                    AVLMenu();
                    break;
                }
                case 3: {
                    MinHeapMenu();
                    break;
                }
                case 4: {
                    MaxHeapMenu();
                    break;
                }
                case 5: {
                    return;
                }
                default: {
                    std::cout << "Invalid Input!\n";
                }
            }
        }
    }

    void printMainMenu() {
        std::cout << "Choose Data Structure:\n"
                  << " 1. BST\n"
                  << " 2. AVL\n"
                  << " 3. Min Heap\n"
                  << " 4. Max Heap\n"
                  << " 5. Exit Program\n";
    }

    int takeUserInput() {
        std::string input;
        int opt = -1;
        while (true) {
            std::cout << ">>>";
            try {
                std::cin >> input;
                opt = std::stoi(input);
                break;
            } catch (std::exception err) {
                std::cout << "Invalid Input!\n";
            }
        }
        return opt;
    }

    void TreeMenu() {
        std::cout << "Choose one of the following options:\n"
                     "1. Add student \n"
                     "2. Remove student\n"
                     "3. Search student\n"
                     "4. Print All (sorted by id)\n"
                     "5. Return to main menu\n";
    }

    void HeapMenu() {
        std::cout << "Choose one of the following options:\n"
                     "1. Add student\n"
                     "2. Print All (sorted by gpa)\n"
                     "3. Return to main menu\n";

    }

    void BSTMenu() {
        while (true) {
            TreeMenu();
            int input = takeUserInput();
            switch (input) {
                case 1: {
                    Student student;
                    std::cin >> student;
                    if (bst.search(student.getId()) != nullptr) {
                        std::cout << "Student with same id already exists!\n";
                        break;
                    }
                    bst.insert(student);
                    std::cout << "The Student is Added!\n";
                    break;
                }
                case 2: {
                    std::cout << "Enter ID to remove:\n";
                    int id;
                    std::cin >> id;
                    if (bst.search(id) != nullptr) {
                        bst.setRoot(bst.remove(bst.getRoot(), id));
                        std::cout << "The Student is Removed!\n";
                    } else { std::cout << "Student not found!\n"; }
                    break;
                }
                case 3: {
                    int id;
                    std::cout << "Enter student id:\n";
                    std::cin >> id;
                    Node *pos = bst.search(id);
                    if (pos != nullptr) {
                        std::cout << "Student is Found.\n";
                        std::cout << pos->student << std::endl;
                    } else {
                        std::cout << "Student is not Found.\n";
                    }
                    break;
                }
                case 4: {
                    if (bst.getSize() != 0) {
                        std::cout << "Printing " << bst.getSize() << " Student(s)...\n";
                        bst.print(bst.getRoot());
                        std::map<std::string, int> departments;
                        std::cout << "Students per Departments:\n";
                        bst.printNumStudentsDepartment(bst.getRoot(), departments);
                    } else {
                        std::cout << "Tree is empty.\n";
                    }
                    break;
                }
                case 5: {
                    return;
                }
                default: {
                    std::cout << "Invalid Input!\n";
                }
            }
        }
    }

    void AVLMenu() {
        while (true) {
            TreeMenu();
            int input = takeUserInput();

            std::map<std::string, int> depCount;
            switch (input) {
                case 1: {
                    Student student;
                    std::cin >> student;
                    if (avl.search(student.getId())) {
                        std::cout << "Student with same id already exists!\n";
                        break;
                    }
                    avl.insert(student.getId(), student);
                    std::cout << "The Student is Added!\n";
                    break;
                }
                case 2: {
                    std::cout << "Enter ID to remove:\n";
                    int id;
                    std::cin >> id;
                    if (avl.search(id)) {
                        avl.remove(id);
                        std::cout << "The Student is Removed!\n";
                    } else { std::cout << "Student not found!\n"; }
                    break;
                }
                case 3: {
                    int id;
                    std::cout << "Enter student id:\n";
                    std::cin >> id;
                    if (avl.search(id)) {
                        std::cout << "Student is Found.\n";
                        std::cout << avl.get(id) << std::endl;
                    } else {
                        std::cout << "Student is not Found.\n";
                    }
                    break;
                }
                case 4: {
                    std::cout << "Print " << avl.getCount() << " Students." << "\n";
                    std::cout << avl << "\n";
                    std::cout << "Student departments: " << "\n";
                    std::map<std::string, int> mp;
                    countDepartment(mp, avl.root);
                    for (auto [dep, cnt]: mp) {
                        std::cout << dep << " " << cnt << "\n";
                    }
                    break;
                }
                case 5: {
                    return;
                }
                default: {
                    std::cout << "Invalid Input!\n";
                }
            }
        }
    }

    void MinHeapMenu() {
        while (true) {
            HeapMenu();
            int input = takeUserInput();
            switch (input) {
                case 1: {
                    Student student;
                    std::cin >> student;
                    if (mnHeap.search(student)) {
                        std::cout << "Student with same id already exists!\n";
                        break;
                    }
                    mnHeap.addStudent(student);
                    std::cout << "The Student is Added!\n";
                    break;
                }
                case 2: {
                    mnHeap.printAllStudents();
                    break;
                }
                case 3: {
                    return;
                }
                default: {
                    std::cout << "Invalid Input!\n";
                }
            }
        }
    }

    void MaxHeapMenu() {
        while (true) {
            HeapMenu();
            int input = takeUserInput();
            switch (input) {
                case 1: {
                    Student student;
                    std::cin >> student;
                    if (mxHeap.search(student)) {
                        std::cout << "Student with same id already exists!\n";
                        break;
                    }
                    mxHeap.addStudent(student);
                    std::cout << "The Student is Added!\n";
                    break;
                }
                case 2: {
                    mxHeap.printAllStudents();
                    break;
                }
                case 3: {
                    return;
                }
                default: {
                    std::cout << "Invalid Input!\n";
                }
            }
        }
    }

    void countDepartment(std::map<std::string, int> &countMap, AVL<int, Student>::AVLNode *curNode) {
        if (curNode == nullptr)
            return;
        countMap[curNode->value.getDepartment()]++;
        countDepartment(countMap, curNode->left);
        countDepartment(countMap, curNode->right);
    }
};