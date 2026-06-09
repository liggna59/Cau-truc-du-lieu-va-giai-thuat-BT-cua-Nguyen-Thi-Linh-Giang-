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
// Ham xoay phai
Node *xoayphai(Node *y) {
    Node *x = y->trai;
    Node *T2 = x->phai;
    // Thuc hien xoay
    x->phai = y;
    y->trai = T2;
    // Cap nhat lai chieu cao
    y->cao = max(cao(y->trai), cao(y->phai)) + 1;
    x->cao = max(cao(x->trai), cao(x->phai)) + 1;
    return x; // Tra ve goc moi
}
// Ham xoay trai
    Node *xoaytrai(Node *x) {
    Node *y = x->phai;
    Node *T2 = y->trai;
    // Thuc hien xoay
    y->trai = x;
    x->phai = T2;
    // Cap nhat lai chieu cao
    x->cao = max(cao(x->trai), cao(x->phai)) + 1;
    y->cao = max(cao(y->trai), cao(y->phai)) + 1;
    return y; // Tra ve goc moi
}
// Lay he so can bang cua nut N
int laycbang(Node *N) {
    if (N == NULL)
        return 0;
    return cao(N->trai) - cao(N->phai);
}




