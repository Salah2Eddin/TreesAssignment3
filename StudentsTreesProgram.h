#pragma once

#include "student.h"


class Program {
public:
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
                    break;
                }
                case 2: {
                    break;
                }
                case 3: {
                    break;
                }
                case 4: {
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
            switch (input) {
                case 1: {
                    break;
                }
                case 2: {
                    break;
                }
                case 3: {
                    break;
                }
                case 4: {
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
                    break;
                }
                case 2: {
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
                    break;
                }
                case 2: {
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

};