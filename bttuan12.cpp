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