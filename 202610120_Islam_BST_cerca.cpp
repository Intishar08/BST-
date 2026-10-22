#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* lchild;
    Node* rchild;

    Node(int n) {
        num = n;
        lchild = nullptr;
        rchild = nullptr;
    }
};

Node* Insert(Node* nodo, int numc) {
    if (nodo == nullptr) {
        return new Node(numc);
    }
    if (numc < nodo->num) {
        nodo->lchild = Insert(nodo->lchild, numc);
    } else if (numc > nodo->num) {
        nodo->rchild = Insert(nodo->rchild, numc);
    }
    return nodo;
}

bool Search(Node* nodo, int numc) {
    if (nodo == nullptr) {
        return false;
    }
    if (numc == nodo->num) {
        return true;
    }
    if (numc < nodo->num) {
        return Search(nodo->lchild, numc);
    }
    return Search(nodo->rchild, numc);
}

Node* findMin(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* corr = root;
    while (corr->lchild != nullptr) {
        corr = corr->lchild;
    }
    return corr;
}

Node* findMax(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }

    Node* corr = root;
    while (corr->rchild != nullptr) {
        corr = corr->rchild;
    }
    return corr;
}

int countNodes(Node* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    return 1 + countNodes(nodo->lchild) + countNodes(nodo->rchild);
}

int countLeaves(Node* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    if (nodo->lchild == nullptr && nodo->rchild == nullptr) {
        return 1;
    }

    return countLeaves(nodo->lchild) + countLeaves(nodo->rchild);
}

int countInRange(Node* nodo, int min, int max) {
    if (nodo == nullptr) {
        return 0;
    }
    if (nodo->num < min) {
        return countInRange(nodo->rchild, min, max);
    }
    if (nodo->num > max) {
        return countInRange(nodo->lchild, min, max);
    }
    return 1 + countInRange(nodo->lchild, min, max) + countInRange(nodo->rchild, min, max);
}
