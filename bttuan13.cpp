#include <iostream>
using namespace std;
// Cau truc mot nut tren cay
struct node {
    int gtri;
    node* trai;
    node* phai;
    node(int x) {
        gtri = x;
        trai = NULL;
        phai = NULL;
    }
};
// Ham them gia tri vao cay nhi phan tim kiem
node* them(node* goc, int x) {
    if (goc == NULL) {
        return new node(x);
    }
    if (x <= goc->gtri) {
        goc->trai = them(goc->trai, x);
    } else {
        goc->phai = them(goc->phai, x);
    }
    return goc;
}
// Ham tim kiem 
bool timkiem(node* goc, int x) {
    if (goc == NULL) {
        cout << " -> NULL (Khong tim thay)" << endl;
        return false;
    }
    cout << goc->gtri;
    if (goc->gtri == x) {
        cout << " (Da tim thay gtri can tim)" << endl;
        return true;
    }
    cout << " -> ";
    if (x <= goc->gtri) {
        return timkiem(goc->trai, x);
    } else {
        return timkiem(goc->phai, x);
    }
}
int main() {
    int dayso[] = {2001, 2002, 2006, 2007, 2003, 2004, 2005, 2001, 1999, 2004};
    int n = sizeof(dayso) / sizeof(dayso[0]);
    node* goc = NULL;
    for (int i = 0; i < n; i++) {
        goc = them(goc, dayso[i]);
    }
    int k = 2004; 
    cout << "\nTim nam sinh " << k << " tren cay:" << endl;
    cout << "Trinh tu duyet cay: ";
    timkiem(goc, k);
    return 0;
}