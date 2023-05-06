#include "AVL.h"

//--------------Main Menu Functions-------------------

void AVL::addStudent(Student &student) {
    InsertRec(root,student);
    cnt++;
}

void AVL::removeStudent(Student &student) {
    bool isFound = Search(student);
    if(isFound){
        Delete(root,student);
        cnt--;
        std::cout << "Student is deleted." << std::endl;
    }
}

void AVL::printAllStudents() {
    std::cout << "Print " << cnt << " Students." << std::endl;
    Print(root);
    std::cout << "Students per Departments: " << std::endl;
    for(auto pair : freqDepartment){
        std::cout << pair.first << " " << pair.second << " Students" << std::endl;
    }
}


//----------------------AVL Functions-------------------------------
AVL::Node *AVL::InsertRec(AVL::Node *p, Student student) {
    if(p == NULL){
        Node* t = new Node();
        t->value = student;
        t->height = 1;
        t->rChild = t->lChild = NULL;
        if(root == NULL) root = t;
        return t;
    }
    if(student.compareByID(p->value)){
        p->lChild = InsertRec(p->lChild,student);
    }
    else{
        p->rChild = InsertRec(p->rChild,student);
    }
    p->height = Height(p);
    int parentBF = BalanceFactor(p);
    int leftChildBF = BalanceFactor(p->lChild);
    int rightChildBF = BalanceFactor(p->rChild);

    if(parentBF == 2 && leftChildBF == 1){
        return rightRotation(p);
    }
    else if(parentBF == 2 && leftChildBF == -1){
        return leftRightRotation(p);
    }
    else if(parentBF == -2 && rightChildBF == -1){
        return leftRotation(p);
    }
    else if(parentBF == -2 && rightChildBF == 1){
        return rightLeftRotation(p);
    }
    return p;
}

AVL::Node *AVL::Delete(AVL::Node *p, Student student) {
    if(!p) return NULL;
    if(!p->rChild && !p->lChild && p->value.getId() == student.getId()){
        if(p == root){
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if(student.compareByID(p->value)){
        p->lChild = Delete(p->lChild,student);
    }
    else if(p->value.compareByID(student)){
        p->rChild = Delete(p->rChild,student);
    }
    else{
        Node* q = new Node();
        if(Height(p->lChild) > Height(p->rChild)){
            q = InPre(p->lChild);
            p->value = q->value;
            p->lChild = Delete(p->lChild,q->value);
        }
        else{
            q = InSucc(p->rChild);
            p->value = q->value;
            p->rChild = Delete(p->rChild,q->value);
        }
    }
    p->height = Height(p);
    int parentBF = BalanceFactor(p);
    int leftChildBF = BalanceFactor(p->lChild);
    int rightChildBF = BalanceFactor(p->rChild);

    if(parentBF == 2 && leftChildBF == 1){
        return rightRotation(p);
    }
    else if(parentBF == 2 && (leftChildBF == -1 || leftChildBF == 0)){
        return leftRightRotation(p);
    }
    else if(parentBF == -2 && rightChildBF == -1){
        return leftRotation(p);
    }
    else if(parentBF == -2 && (rightChildBF == 1 || rightChildBF == 0)){
        return rightLeftRotation(p);
    }
    return p;
}

bool AVL::Search(Student student) {
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

void AVL::Print(AVL::Node *p) {
    if(p){
        Print(p->lChild);
        freqDepartment[p->value.getDepartment()]++;
        std::cout << p->value << std::endl;
        Print(p->rChild);
    }
}

int AVL::Height(AVL::Node *p) {
    int leftHeight, rightHeight;
    leftHeight = p && p->lChild ? p->lChild->height : 0;
    rightHeight = p && p->rChild ? p->rChild->height : 0;
    return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
}

AVL::Node *AVL::InPre(AVL::Node *p) {
    while(p && p->rChild){
        p = p->rChild;
    }
    return p;
}

AVL::Node *AVL::InSucc(AVL::Node *p) {
    while(p && p->lChild){
        p = p->lChild;
    }
    return p;
}

int AVL::BalanceFactor(AVL::Node *p) {
    int leftHeight= p && p->lChild ? p->lChild->height : 0;
    int rightHeight = p && p->rChild ? p->rChild->height : 0;
    return leftHeight - rightHeight;
}

AVL::Node * AVL::leftRotation(Node* p) {
    Node* pr = p->rChild;
    Node* prl = pr->lChild;
    p->rChild = prl;
    pr->lChild = p;
    p->height = Height(p);
    pr->height = Height(pr);
    if(root == p){
        root = pr;
    }
    return pr;
}

AVL::Node * AVL::rightRotation(Node* p) {
    Node* pl = p->lChild;
    Node* plr = pl->rChild;
    p->lChild = plr;
    pl->rChild = p;

    pl->height = Height(pl);
    p->height = Height(p);
    if(root == p){
        root = pl;
    }
    return pl;
}

AVL::Node *AVL::leftRightRotation(AVL::Node *p) {
    Node* pl = p->lChild;
    Node* plr = pl->rChild;

    pl->rChild = plr->lChild;
    p->lChild = plr->rChild;

    plr->lChild = pl;
    plr->rChild = p;

    plr->height = Height(plr);
    pl->height = Height(pl);
    p->height = Height(p);

    if(root == p){
        root = plr;
    }
    return plr;
}

AVL::Node *AVL::rightLeftRotation(AVL::Node *p) {
    Node* pr = p->rChild;
    Node* prl = pr->lChild;

    pr->lChild = prl->rChild;
    p->rChild = prl->lChild;

    prl->lChild = p;
    prl->rChild = pr;

    prl->height = Height(prl);
    pr->height = Height(pr);
    p->height = Height(p);
    if(root == p){
        root = prl;
    }
    return prl;
}
