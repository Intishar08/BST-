#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node(int k) {
        data = k;
        left = nullptr;
        right = nullptr;
    }

    int getData() {
        return data;
    }

    Node* getLeft() {
        return left;
    }

    Node* getRight() {
        return right;
    }

    void setData(int newData) {
        data = newData;
    }

    void setLeft(Node* newLeft) {
        left = newLeft;
    }

    void setRight(Node* newRight) {
        right = newRight;
    }

    bool isLeaf() {
        return left == nullptr && right == nullptr;
    }
};

class BST {
private:
    Node* root;
    int numNodi;

    void inOrderRec(Node* n) {
        if (n == nullptr) {
            return;
        }
        inOrderRec(n->getLeft());
        cout << n->getData() << " ";
        inOrderRec(n->getRight());
    }

    int heightRec(Node* n) {
        if (n == nullptr) {
            return 0;
        }
        int hl = heightRec(n->getLeft());
        int hr = heightRec(n->getRight());
        if (hl > hr) {
            return 1 + hl;
        }
        return 1 + hr;
    }

    Node* removeRec(Node* n, int k, bool& removed) {
        if (n == nullptr) {
            return nullptr;
        }

        if (k < n->getData()) {
            n->setLeft(removeRec(n->getLeft(), k, removed));
        } else if (k > n->getData()) {
            n->setRight(removeRec(n->getRight(), k, removed));
        } else {
            removed = true;

            if (n->isLeaf()) {
                delete n;
                return nullptr;
            }
            if (n->getLeft() == nullptr) {
                Node* figlio = n->getRight();
                delete n;
                return figlio;
            }
            if (n->getRight() == nullptr) {
                Node* figlio = n->getLeft();
                delete n;
                return figlio;
            }

            Node* succ = n->getRight();
            while (succ->getLeft() != nullptr) {
                succ = succ->getLeft();
            }
            int chiaveSucc = succ->getData();
            n->setData(chiaveSucc);
            bool dummy = false;
            n->setRight(removeRec(n->getRight(), chiaveSucc, dummy));
        }
        return n;
    }

    void svuotaRec(Node* n) {
        if (n == nullptr) {
            return;
        }
        svuotaRec(n->getLeft());
        svuotaRec(n->getRight());
        delete n;
    }

    int contaFoglieRec(Node* n) {
        if (n == nullptr) {
            return 0;
        }
        if (n->isLeaf()) {
            return 1;
        }
        return contaFoglieRec(n->getLeft()) + contaFoglieRec(n->getRight());
    }

    int contaIntervalloRec(Node* n, int low, int high) {
        if (n == nullptr) {
            return 0;
        }
        if (n->getData() < low) {
            return contaIntervalloRec(n->getRight(), low, high);
        }
        if (n->getData() > high) {
            return contaIntervalloRec(n->getLeft(), low, high);
        }
        return 1 + contaIntervalloRec(n->getLeft(), low, high)
                 + contaIntervalloRec(n->getRight(), low, high);
    }

public:
    BST() {
        root = nullptr;
        numNodi = 0;
    }

    ~BST() {
        svuota();
    }

    bool isEmpty() {
        return root == nullptr && numNodi == 0;
    }

    int size() {
        return numNodi;
    }

    bool insert(int k) {
        if (root == nullptr) {
            root = new Node(k);
            numNodi++;
            return true;
        }

        Node* corrente = root;

        while (true) {
            if (k == corrente->getData()) {
                return false;
            }

            if (k < corrente->getData()) {
                if (corrente->getLeft() == nullptr) {
                    corrente->setLeft(new Node(k));
                    numNodi++;
                    return true;
                }
                corrente = corrente->getLeft();
            } else {
                if (corrente->getRight() == nullptr) {
                    corrente->setRight(new Node(k));
                    numNodi++;
                    return true;
                }
                corrente = corrente->getRight();
            }
        }
    }

    bool search(int k) {
        Node* corrente = root;

        while (corrente != nullptr) {
            if (k == corrente->getData()) {
                return true;
            }
            if (k < corrente->getData()) {
                corrente = corrente->getLeft();
            } else {
                corrente = corrente->getRight();
            }
        }

        return false;
    }

    void inOrder() {
        inOrderRec(root);
    }

    int height() {
        return heightRec(root);
    }

    int minimo() {
        if (root == nullptr) {
            return -1;
        }

        Node* c = root;

        while (c->getLeft() != nullptr) {
            c = c->getLeft();
        }

        return c->getData();
    }

    int massimo() {
        if (root == nullptr) {
            return -1;
        }

        Node* c = root;

        while (c->getRight() != nullptr) {
            c = c->getRight();
        }

        return c->getData();
    }

    bool remove(int k) {
        bool removed = false;
        root = removeRec(root, k, removed);
        if (removed) {
            numNodi--;
        }
        return removed;
    }

    void svuota() {
        svuotaRec(root);
        root = nullptr;
        numNodi = 0;
    }

    int contaFoglie() {
        return contaFoglieRec(root);
    }

    int contaIntervallo(int low, int high) {
        return contaIntervalloRec(root, low, high);
    }
};

