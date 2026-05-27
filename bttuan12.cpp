#include <iostream>
#include <vector>
using namespace std;
// Hàm in mảng sau mỗi thao tác
void intrangthaimang(const vector<int>& mangtruyenvao) {
    cout << "[ ";
    for (int i = 0; i < mangtruyenvao.size(); i++) {
        cout << mangtruyenvao[i] << " ";
    }
    cout << "]" << endl;
}
// Hàm vun đống tại một node
void vundong(vector<int>& mangdangxet, int n, int i) {
    int lonnhat = i;
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;
    if (trai < n && mangdangxet[trai] > mangdangxet[lonnhat]) {
        lonnhat = trai;
    }
    if (phai < n && mangdangxet[phai] > mangdangxet[lonnhat]) {
        lonnhat = phai;
    }
    if (lonnhat != i) {
        swap(mangdangxet[i], mangdangxet[lonnhat]);
        // Vun đống lại đệ quy
        vundong(mangdangxet, n, lonnhat);
    }
}
// Hàm sắp xếp vun đống
void sapxepvundong(vector<int>& mangdangxet) {
    int n = mangdangxet.size();
    cout << "Tao dong ban dau" << endl;
    for (int i = n / 2 - 1; i >= 0; i--) {
        vundong(mangdangxet, n, i);
        cout << "Sau khi vun dong tai node" << i << ": ";
        intrangthaimang(mangdangxet);
    }
    cout << "Sap xep vun dong " << endl;
    for (int i = n - 1; i > 0; i--) {
        swap(mangdangxet[0], mangdangxet[i]);
        cout << "Hoan vi nut goc  voi mang dang xet[" << i << "]: ";
        intrangthaimang(mangdangxet);
        vundong(mangdangxet, i, 0);
        cout << "Vun dong lai nut goc: ";
        intrangthaimang(mangdangxet);
    }
}
int main() {
    //cây ví dụ trong Slide
    vector<int> mang1 = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    // cây ví dụ trên bảng
    vector<int> mang2 = {203, 106, 78, 84, 59, 15, 32, 16, 10, 17, 38, 11};
    cout << "Cay trong slide" << endl;
    cout << "Mang ban dau: ";
    intrangthaimang(mang1);
    sapxepvundong(mang1);
    cout << "\nCay tren bang" << endl;
    cout << "Mang ban dau: ";
    intrangthaimang(mang2);
    sapxepvundong(mang2);
    return 0;
}