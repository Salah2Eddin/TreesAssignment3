#include "BST.h"

BST::~BST() {
//    for (int i = 0; i < size; ++i) {
//        delete nodes[i];
//    }
}

void BST::insert(Student student) {
    if (root == nullptr) {
        root = new Node(student);
    } else {
        Node *current = root, *parent;
        while (current != nullptr) {
            parent = current;
            if (student.compareByID(current->student)) {
                current = current->lChild;
            } else {
                current = current->rChild;
            }
        }
        if (student.compareByID(parent->student)) {
            parent->lChild = new Node(student);
        } else {
            parent->rChild = new Node(student);
        }
    }
    size++;
}

Node *BST::remove(Node *current, int id) {
    if (current == nullptr) {
        return current;
    } else if (id < current->student.getId()) {
        current->lChild = remove(current->lChild, id);
    } else if (id > current->student.getId()) {
        current->rChild = remove(current->rChild, id);
    } else {
        //Case 1: No Children
        if (current->lChild == nullptr && current->rChild == nullptr) {
            delete current;
            current = nullptr;
        }
        //Case 2: One Child
        else if (current->lChild == nullptr) {
            Node *tmp = current;
            current = current->rChild;
            delete tmp;
        }
        else if (current->rChild == nullptr) {
            Node *tmp = current;
            current = current->lChild;
            delete tmp;
        }
        //Case 3: Two Children
        else {
            Node *tmp = findMin(current->rChild);
            current->student = tmp->student;
            current->rChild = remove(current->rChild, tmp->student.getId());
        }
    }
    size--;
    return current;
}

Node *BST::search(int id) {
    Node *current = root;
    while (current != nullptr) {
        if (current->student.getId() == id) {
            return current;
        } else if (id < current->student.getId()) {
            current = current->lChild;
        } else {
            current = current->rChild;
        }
    }
    return nullptr;
}

void BST::print(Node* current) {
    if (root == nullptr) {
        std::cout << "Tree is empty.\n";
    } else if (current) {
        print(current->lChild);
        std::cout << current->student << std::endl;
        print(current->rChild);
    }
}

int BST::getSize() {
    return size;
}

Node *BST::getRoot() {
    return root;
}

void BST::getNumStudentsDepartment(Node *current, std::map<std::string, int> &departments) {
    if (current) {
        getNumStudentsDepartment(current->lChild, departments);
        departments[current->student.getDepartment()]++;
        getNumStudentsDepartment(current->rChild, departments);
    }
}

void BST::printNumStudentsDepartment(Node *current, std::map<std::string, int> &departments) {
    getNumStudentsDepartment(current, departments);
    for (const auto &pair : departments)
        std::cout << pair.first << ' ' << pair.second << " Student(s)\n";
}

void BST::setRoot(Node *root) {
    this->root = root;
}

Node *BST::findMin(Node *rSubTree) {
    Node *current = rSubTree;
    while (current->lChild != nullptr) {
        current = current->lChild;
    }
    return current;
}



