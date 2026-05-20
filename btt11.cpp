// cau truc luu tru tuan tu
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// Hàm in mảng luu tru cay
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
    cout << "Cay day du:    "; 
    luutrucay(caydaydu);   
    // Kích thước mang luu tru cay nhi phan la 2^n - 1
    int kichthuoc = pow(2, n) - 1;   
    // Cây lệch trái
    vector<int> caylechtrai(kichthuoc, -1);
    int vtri = 0; 
    for (int i = 0; i < n; i++) {
        caylechtrai[vtri] = dulieu[i];
        vtri = 2 * vtri + 1; 
    }
    cout << "Cay lech trai: "; 
    luutrucay(caylechtrai); 
    // Cây lệch phải
    vector<int> caylechphai(kichthuoc, -1);
    vtri = 0;
    for (int i = 0; i < n; i++) {
        caylechphai[vtri] = dulieu[i];
        vtri = 2 * vtri + 2; 
    }
    cout << "Cay lech phai: "; 
    luutrucay(caylechphai);  
    // Cây Zigzac (Trái -> Phải -> Trái -> Phải)
    vector<int> cayzigzac(kichthuoc, -1);
    vtri = 0;
    for (int i = 0; i < n; i++) {
        cayzigzac[vtri] = dulieu[i];
        if (i % 2 == 0) vtri = 2 * vtri + 1; 
        else vtri = 2 * vtri + 2;            
    }
    cout << "Cay zigzac:    "; 
    luutrucay(cayzigzac);   
    return 0;
}
// cau truc luu tru moc noi (dung con tro)
#include <iostream>
#include <vector>

using namespace std;

// Khai báo cấu trúc của 1 Nút (Node)
struct Nut {
    int duLieu;
    Nut* trai;
    Nut* phai;
    
    // Hàm khởi tạo để gán giá trị nhanh
    Nut(int giaTri) {
        duLieu = giaTri;
        trai = nullptr;
        phai = nullptr;
    }
};

// 1. Khởi tạo Cây đầy đủ (dùng công thức 2*i+1 và 2*i+2 giống mảng)
Nut* taoCayDayDu(const vector<int>& mang, int i = 0) {
    if (i >= mang.size()) return nullptr;
    
    Nut* goc = new Nut(mang[i]);
    goc->trai = taoCayDayDu(mang, 2 * i + 1);
    goc->phai = taoCayDayDu(mang, 2 * i + 2);
    
    return goc;
}

// 2. Khởi tạo Cây lệch trái
Nut* taoCayLechTrai(const vector<int>& mang, int i = 0) {
    if (i >= mang.size()) return nullptr;
    
    Nut* goc = new Nut(mang[i]);
    goc->trai = taoCayLechTrai(mang, i + 1); // Chỉ mọc con trái
    
    return goc;
}

// 3. Khởi tạo Cây lệch phải
Nut* taoCayLechPhai(const vector<int>& mang, int i = 0) {
    if (i >= mang.size()) return nullptr;
    
    Nut* goc = new Nut(mang[i]);
    goc->phai = taoCayLechPhai(mang, i + 1); // Chỉ mọc con phải
    
    return goc;
}

// 4. Khởi tạo Cây Zigzac (Trái -> Phải -> Trái...)
Nut* taoCayZigzac(const vector<int>& mang, int i = 0) {
    if (i >= mang.size()) return nullptr;
    
    Nut* goc = new Nut(mang[i]);
    if (i + 1 < mang.size()) {
        if (i % 2 == 0) goc->trai = taoCayZigzac(mang, i + 1);  // Lần chẵn: rẽ trái
        else goc->phai = taoCayZigzac(mang, i + 1);             // Lần lẻ: rẽ phải
    }
    
    return goc;
}

// Hàm duyệt cây theo thứ tự Giữa (In-order: Trái - Gốc - Phải) để in kết quả
void inCay(Nut* goc) {
    if (goc == nullptr) return;
    inCay(goc->trai);
    cout << goc->duLieu << " ";
    inCay(goc->phai);
}

int main() {
    vector<int> dulieu = {10, 20, 30, 40};
    
    cout << "--- CAU TRUC MOC NOI (In theo thu tu giua) ---\n";
    
    Nut* cayDayDu = taoCayDayDu(dulieu);
    cout << "1. Cay day du:   "; 
    inCay(cayDayDu); 
    cout << "\n";

    Nut* cayLechTrai = taoCayLechTrai(dulieu);
    cout << "2. Cay lech trai: "; 
    inCay(cayLechTrai); 
    cout << "\n";

    Nut* cayLechPhai = taoCayLechPhai(dulieu);
    cout << "3. Cay lech phai: "; 
    inCay(cayLechPhai); 
    cout << "\n";

    Nut* cayZigzac = taoCayZigzac(dulieu);
    cout << "4. Cay zigzac:    "; 
    inCay(cayZigzac); 
    cout << "\n";

    return 0;
}