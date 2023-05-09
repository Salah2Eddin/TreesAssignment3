#include "BST.h"

BST::~BST() {
    delete root;
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
    if (current == nullptr)
        return current;

    if (current->lChild == nullptr && current->rChild == nullptr) {
        if (current == root)
            root = nullptr;
        delete current;
        current = nullptr;
    } else if (id < current->student.getId()) {
        current->lChild = remove(current->lChild, id);
    } else if (id > current->student.getId()) {
        current->rChild = remove(current->rChild, id);
    } else {
        Node *tmp;
        if (current->lChild == nullptr) {
            tmp = InorderSuccessor(current->rChild);
            current->student = tmp->student;
            current->rChild = remove(current->rChild, tmp->student.getId());
        } else {
            tmp = InorderPredecessor(current->lChild);
            current->student = tmp->student;
            current->lChild = remove(current->lChild, tmp->student.getId());
        }
    }
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


Node *BST::InorderSuccessor(Node *rSubTree) {
    while (rSubTree && rSubTree->lChild != nullptr) {
        rSubTree = rSubTree->lChild;
    }
    return rSubTree;
}

Node *BST::InorderPredecessor(Node *lSubTree) {
    while (lSubTree && lSubTree->rChild != nullptr) {
        lSubTree = lSubTree->rChild;
    }
    return lSubTree;
}

void BST::decrementSize(int decrement) {
    this->size = size - decrement;
}



