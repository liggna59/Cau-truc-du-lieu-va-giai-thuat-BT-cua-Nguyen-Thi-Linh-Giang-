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
    if (N == NULL) // Nút rỗng thì độ lệch bằng 0
        return 0;
    return cao(N->trai) - cao(N->phai);
}
// Ham chen mot gia tri vao cay AVL
Node* insert(Node* node, int so) //chen nhu cay nhi phan tim kiem binh thuong
{ 
    if (node == NULL)
        return newNode(so);
    if (so <node->so)
        node-> trai = insert(node->trai, so);
    else if (so > node->so)
        node->phai = insert(node->phai, so);
    else 
        return node;
    //Cap nhat chieu cao cua node to tien nay
    node->cao = 1 + max(cao(node->trai), cao(node->phai));
    //Lay he so can bang de kiem tra xem nut nay co bi mat can bang khong
    int cbang = laycbang(node);
    // Neu nut bi mat can bang, se co 4 truong hop xay ra:
    // Truong hop Trai - Trai
    if (cbang > 1 && so < node->trai->so)
        return xoayphai(node);
    // Truong hop Phai Phai
    if (cbang < -1 && so > node->phai->so)
        return xoaytrai(node);
    // Truong hop Trai - Phai
    if (cbang > 1 && so > node->trai->so) {
        node->trai = xoaytrai(node->trai);
        return xoayphai(node);
    }
    // Truong hop Phai trai
    if (cbang < -1 && so < node->phai->so) {
        node->phai = xoayphai(node->phai);
        return xoaytrai(node);
    }
    return node; // Tra ve con tro (khong doi)
}
// Ham duyet cay theo thu tu giua ( Trai - Goc - Phai)
void duyetgiua(Node *goc) {
    if (goc != NULL) {
        duyetgiua(goc->trai);
        cout << goc->so << " ";
        duyetgiua(goc->phai);
    }
}
// Ham duyet cay theo thu tu truoc (Goc - Trai - Phai) 
void duyettruoc(Node *goc) {
    if (goc != NULL) {
        cout << goc->so << " ";
        duyettruoc(goc->trai);
        duyettruoc(goc->phai);
    }
}
int main() {
    Node *goc = NULL;
    // Day so dau vao theo yeu cau cua de bai
    int arr[] = {32, 51, 27, 83, 96, 11, 45, 75, 66, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    // them cac phan tu vao cay AVL
    for (int i = 0; i < n; i++) {
        goc = insert(goc, arr[i]);
    }
    // In ket qua
    cout << "Day so dau vao: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\nDuyet cay theo thu tu giua: \n";
    duyetgiua(goc);
    cout << endl;
    cout << "\nDuyet cay theo thu tu truoc: \n";
    duyettruoc(goc);
    cout << endl;
    return 0;
}