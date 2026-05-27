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