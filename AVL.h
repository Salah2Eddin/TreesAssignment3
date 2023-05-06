#pragma once

#include <exception>
#include <iostream>

template<typename TK, typename TV>
class AVL {
    struct AVLNode {
        TK key;
        TV value;
        AVL::AVLNode *left = nullptr, *right = nullptr;
        int height = 1;

        AVLNode(TK key, TV value) : key(key), value(value) {}

        void updateHeight() {
            height = std::max((left == nullptr) ? 0 : left->height, (right == nullptr) ? 0 : right->height) + 1;
        }

        int getBalance() {
            return (left == nullptr ? 0 : left->height) - (right == nullptr ? 0 : right->height);
        }

        bool operator<(AVL::AVLNode &other) const {
            return key < other.key;
        }
    };

    AVLNode *root = nullptr;
public:
    AVL() = default;

    // insert
    void insert(TK key, TV value) {
        auto *newNode = new AVLNode(key, value);
        root = insert(root, newNode);
    }

    AVLNode *insert(AVLNode *curNode, AVLNode *newNode) {
        if (curNode == nullptr) {
            curNode = newNode;
            return curNode;
        } else if (curNode->key > newNode->key) {
            curNode->left = insert(curNode->left, newNode);
        } else if (curNode->key < newNode->key) {
            curNode->right = insert(curNode->right, newNode);
        } else {
            throw std::exception();
        }

        curNode->updateHeight();
        // balancing
        int balance = curNode->getBalance();
        if (balance > 1 && newNode->key < curNode->left->key) {
            return shiftRight(curNode);
        } else if (balance > 1 && newNode->key > curNode->left->key) {
            return shiftLeftRight(curNode);
        } else if (balance < -1 && newNode->key < curNode->right->key) {
            return shiftRightLeft(curNode);
        } else if (balance < -1 && newNode->key > curNode->right->key) {
            return shiftLeft(curNode);
        }
        return curNode;
    }

    // delete
    void remove(TK key) {
        root = remove(root, key);
    }

    AVLNode *remove(AVLNode *curNode, TK key) {
        if (curNode == nullptr) {
            throw std::exception();
        } else if (key < curNode->key) {
            curNode->left = remove(curNode->left, key);
        } else if (key > curNode->key) {
            curNode->right = remove(curNode->right, key);
        } else {
            // one or zero children
            if (curNode->left == nullptr) {
                AVLNode *newCurNode = curNode->right;
                delete curNode;
                return newCurNode;
            } else if (curNode->right == nullptr) {
                AVLNode *newCurNode = curNode->left;
                delete curNode;
                return newCurNode;
            }

            AVLNode *newCurNode = minimumKey(curNode->right);

            curNode->key = newCurNode->key;
            curNode->value = newCurNode->value;

            curNode->right = remove(curNode->right, newCurNode->key);
        }

        curNode->updateHeight();

        int balance = curNode->getBalance();

        if (balance > 1 && curNode->left->getBalance() >= 0)
            return shiftRight(curNode);
        else if (balance > 1 && curNode->left->getBalance() < 0) {
            return shiftLeftRight(curNode);
        } else if (balance < -1 && curNode->right->getBalance() <= 0)
            return shiftLeft(curNode);
        else if (balance < -1 && curNode->right->getBalance() > 0) {
            return shiftRightLeft(curNode);
        }
        return curNode;
    }

    // print
    void print(std::ostream &os) {
        print(os, root);
    }

    void print(std::ostream &os, AVLNode *curNode) {
        if (curNode == nullptr)
            return;
        print(os, curNode->left);
        os << curNode->value << " ";
        print(os, curNode->right);
    }

    friend std::ostream &operator<<(std::ostream &os, AVL<TK, TV> &avl) {
        avl.print(os);
        return os;
    }

    // search
    bool search(TK key) {
        return search(key, root);
    }

    bool search(TK key, AVLNode *curNode) {
        if (curNode == nullptr)
            return false;
        else if (curNode->key > key) {
            return search(key, curNode->left);
        } else if (curNode->key < key) {
            return search(key, curNode->right);
        } else if (curNode->key == key) {
            return true;
        }
        return false;
    }

    // minimum key in subtree
    AVLNode *minimumKey(AVLNode *subtreeRoot) {
        AVLNode *curNode = subtreeRoot;
        while (curNode->left != nullptr) {
            curNode = curNode->left;
        }
        return curNode;
    }

    // shifts R, L, LR, RL
    AVLNode *shiftRight(AVLNode *z) {
        AVLNode *y = z->left;
        AVLNode *t3 = y->right;

        z->updateHeight();
        y->updateHeight();
        // rotate
        z->left = t3;
        y->right = z;
        return y;
    }

    AVLNode *shiftLeft(AVLNode *z) {
        AVLNode *y = z->right;
        AVLNode *t3 = y->left;

        // rotate
        z->right = t3;
        y->left = z;
        // new height
        z->updateHeight();
        y->updateHeight();
        return y;
    }

    AVLNode *shiftLeftRight(AVLNode *z) {
        z->left = shiftLeft(z->left);
        return shiftRight(z);
    }

    AVLNode *shiftRightLeft(AVLNode *z) {
        z->right = shiftRight(z->right);
        return shiftLeft(z);
    }
};