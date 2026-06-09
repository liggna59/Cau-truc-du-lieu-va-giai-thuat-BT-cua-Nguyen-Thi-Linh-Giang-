#include <iostream>
using namespace std;
//cau truc cua 1 node trong cay AVL
struct Node {
    int so; //gia tri cua node
    Node *trai;
    Node *phai;
    int cao;
};
// Tim chieu cao cua node
int cao(Node *N) {
    if (N == NULL)
        return 0;
    return N->cao;
}
// So sanh gia tri cua 2 nod, tra ve gia tri lon hon
int max(int a, int b) {
    return (a > b) ? a : b;
}
// Ham tao 1 node moi
Node* newNode(int so) {
    Node* node = new Node();
    node->so = so;
    node->trai = NULL;
    node->phai = NULL;
    node->cao = 1; // Nut moi them vao luoon o duoi cung, co chieu cao mac dinh la 1
    return node;
}

