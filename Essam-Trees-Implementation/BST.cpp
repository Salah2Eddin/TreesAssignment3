#include "BST.h"



//--------------Main Menu Functions-------------------
void BST::addStudent(Student& student) {
//    InsertRec(root,student);
    InsertItr(student);
    cnt++;
}

void BST::printAllStudents() {
    std::cout << "Print " << cnt << " Students." << std::endl;
    Print(root);
    std::cout << "Students per Departments: " << std::endl;
    for(auto pair : freqDepartment){
        std::cout << pair.first << " " << pair.second << " Students" << std::endl;
    }
}

void BST::removeStudent(Student &student) {
    bool isFound = Search(student);
    if(isFound){
        Delete(root,student);
        cnt--;
        std::cout << "Student is deleted." << std::endl;
    }

}



//----------------------BST Functions-------------------------------
BST::Node * BST::InsertRec(Node* p, Student student) {
    Node* t = new Node();
    if(p == NULL){
        t->value = student;
        t->rChild = t->lChild = NULL;
        if(root == NULL) root = t;
        return t;
    }

    if(student.compareByID(p->value)){
        p->lChild = InsertRec(p->lChild, student);
    }
    else if(p->value.compareByID(student)){
        p->rChild = InsertRec(p->rChild, student);
    }
    return p;
}

void BST::InsertItr(Student student) {
    Node* p = root;
    Node* t = new Node();
    t->value = student;
    t->rChild = t->lChild = NULL;

    if(root == NULL){
        root = t;
        return;
    }
    else{
        Node* r = NULL;
        while(p){
            r = p;
            if(student.compareByID(p->value)){
                p = p->lChild;
            }
            else{
                p = p->rChild;
            }
        }
        if(student.compareByID(r->value)){
            r->lChild = t;
        }
        else{
            r->rChild = t;
        }
    }
}

BST::Node * BST::Delete(Node* p, Student student) {
    if(!p) return NULL;
    if(!p->lChild && !p->rChild && p->value.getId() == student.getId()){
        if(p == root){
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if(student.compareByID(p->value)){
        p->lChild = Delete(p->lChild, student);
    }
    else if(p->value.compareByID(student)){
        p->rChild = Delete(p->rChild,student);
    }
    else{
        if(Height(p->lChild) > Height(p->rChild)){
            Node* q = new Node();
            q = InPre(p->lChild);
            p->value = q->value;
            p->lChild = Delete(p->lChild, q->value);
        }
        else{
            Node* q = new Node();
            q = InSucc(p->rChild);
            p->value = q->value;
            p->rChild = Delete(p->rChild, q->value);
        }
    }
    return p;
}

bool BST::Search(Student student) {
    Node* p = root;
    while(p){
        if(p->value.getId() == student.getId()){
            std::cout << "Student Found" << std::endl;
            std::cout << student << std::endl;
            return true;
        }
        else if(student.compareByID(p->value)){
            p = p->lChild;
        }
        else{
            p = p->rChild;
        }
    }
    std::cout << "Student Not Found" << std::endl;
    return false;
}

void BST::Print(Node* p) {
    if(p){
        Print(p->lChild);
        freqDepartment[p->value.getDepartment()]++;
        std::cout << p->value << std::endl;
        Print(p->rChild);
    }
}

int BST::Height(Node *p) {
    int rightHeight, leftHeight;
    if(!p) return 0;
    leftHeight = Height(p->lChild);
    rightHeight = Height(p->rChild);

    return (rightHeight < leftHeight ? leftHeight + 1 : rightHeight + 1);
}

BST::Node * BST::InPre(Node *p) {

    while(p && p->rChild){
        p = p->rChild;
    }
    return p;
}

BST::Node * BST::InSucc(Node *p) {
    while(p && p->lChild){
        p = p->lChild;
    }
    return p;
}
//-----------------------------------------------------------

