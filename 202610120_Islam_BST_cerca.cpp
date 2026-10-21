#include <iosstream>
using namespace std;

struct Node {
    int num;
    Node* left;
    Node* left;

    Node(int n){
         num = n;
        left=nullptr;
        right=nullptr;
    }
};

bool cerca(Nodo* nodo, int numc ) {
    if (nodo == nullptr) {
        return false;
    }
    if (numc == nodo->numc) {
        return true;
    }
    if (numc < nodo->numc) {
        return cerca(nodo->sinistro, numc);
    }
    return cerca(nodo->destro, numc);
}
