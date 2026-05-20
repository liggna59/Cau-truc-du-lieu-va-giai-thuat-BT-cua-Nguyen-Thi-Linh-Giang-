// cau truc luu tru tuan tu
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Hàm mang luu tru cay
void luutrucay(const vector<int>& cay) {
    for (int i = 0; i < cay.size(); i++) {
        if (cay[i] == -1) cout << "_ ";
        else cout << cay[i] << " ";
    }
    cout << "\n";
}
int main() {
    vector<int> dulieu = {10, 20, 30, 40};
    int n = dulieu.size();
    // Cây đầy đủ 
    vector<int> caydaydu = dulieu;
    cout << "Cay day du:   "; 
    inMangCay(caydaydu);
    // Kích thước mang luu tru cay nhi phan la 2^n - 1
    int kichthuoc = pow(2, n) - 1;
    // Cây lệch trái
    vector<int> caylechtrai(kichthuoc, -1);
    int vtri = 0; 
    for (int i = 0; i < n; i++) {
        caylechtrai[vt] = dulieu[i];
        vt = 2 * vt + 1; 
    }
    cout << "Cay lech trai: "; 
    luutrucay(caylechtrai);
    // Cây lệch phải
    vector<int> caylechhai(kichthuoc, -1);
    vtri = 0;
    for (int i = 0; i < n; i++) {
        caylechphai[vt] = dulieu[i];
        vt = 2 * vt + 2; 
    }
    cout << "Cay lech phai: "; 
    inMangCay(caylechphai);
    // Cây Zigzac (Trái -> Phải -> Trái -> Phải)
    vector<int> cayzigzac(kichthuoc, -1);
    vtri = 0;
    for (int i = 0; i < n; i++) {
        cayzigzac[vt] = dulieu[i];
        if (i % 2 == 0) vtri = 2 * vt + 1; 
        else vtri = 2 * vtri + 2;            
    }
    cout << "Cay zigzac:    "; 
    inMangCay(cayzigzac);
    return 0;
}