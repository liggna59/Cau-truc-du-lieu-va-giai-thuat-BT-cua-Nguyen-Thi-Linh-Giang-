// cau truc luu tru moc noi
#include <iostream>
#include <vector>
#include <stack>  
#include <string> 
using namespace std;
struct Node {
    int dulieu;
    Node* trai;
    Node* phai;
    Node(int gtri) {
        dulieu = gtri;
        trai = nullptr;
        phai = nullptr;
    }
};
Node* taocaydaydu(const vector<int>& arr, int i = 0) {
    if (i >= arr.size()) return nullptr;
    Node* goc = new Node(arr[i]);
    goc->trai = taocaydaydu(arr, 2 * i + 1);
    goc->phai = taocaydaydu(arr, 2 * i + 2);
    return goc;
}
Node* taocaylechtrai(const vector<int>& arr, int i = 0) {
    if (i >= arr.size()) return nullptr;
    Node* goc = new Node(arr[i]);
    goc->trai = taocaylechtrai(arr, i + 1);
    return goc;
}
Node* taocaylechphai(const vector<int>& arr, int i = 0) {
    if (i >= arr.size()) return nullptr;
    Node* goc = new Node(arr[i]);
    goc->phai = taocaylechphai(arr, i + 1);
    return goc;
}
Node* taocayzigzac(const vector<int>& arr, int i = 0) {
    if (i >= arr.size()) return nullptr;
    Node* goc = new Node(arr[i]);
    if (i + 1 < arr.size()) {
        if (i % 2 == 0) goc->trai = taocayzigzac(arr, i + 1); 
        else goc->phai = taocayzigzac(arr, i + 1);            
    }
    return goc;
}
// Duyệt cây theo thứ tự giữa
void incay(Node* goc) {
    if (goc == nullptr) return;
    incay(goc->trai);
    cout << goc->dulieu << " ";
    incay(goc->phai);
}
// Cay bieu thuc va phep duyet cay bieu thuc
struct Nodebieuthuc {
    char dulieu;
    Nodebieuthuc* trai;
    Nodebieuthuc* phai;
    Nodebieuthuc(char gtri) {
        dulieu = gtri;
        trai = nullptr;
        phai = nullptr;
    }
};
bool toantu(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
Nodebieuthuc* taocaybieuthuc(string hauto) {
    stack<Nodebieuthuc*> stack;
    for (int i = 0; i < hauto.length(); i++) {
        char c = hauto[i];
        Nodebieuthuc* nut = new Nodebieuthuc(c);
        if (toantu(c)) {
            nut->phai = stack.top(); stack.pop();
            nut->trai = stack.top(); stack.pop();
        }
        stack.push(nut);
    }
    return stack.top();
}
void duyettruoc(Nodebieuthuc* goc) {
    if (goc == nullptr) return;
    cout << goc->dulieu << " ";
    duyettruoc(goc->trai);
    duyettruoc(goc->phai);
}
void duyetgiua(Nodebieuthuc* goc) {
    if (goc == nullptr) return;
    if (toantu(goc->dulieu)) cout << "( ";
    duyetgiua(goc->trai);
    cout << goc->dulieu << " ";
    duyetgiua(goc->phai);
    if (toantu(goc->dulieu)) cout << ") ";
}
void duyetsau(Nodebieuthuc* goc) {
    if (goc == nullptr) return;
    duyetsau(goc->trai);
    duyetsau(goc->phai);
    cout << goc->dulieu << " ";
}
//chay chuong trinh
int main() {
    vector<int> dulieu = {10, 20, 30, 40}; 
    cout << "luu tru moc noi\n";
    Node* caydaydumn = taocaydaydu(dulieu);
    cout << "Cay day du:   "; 
    incay(caydaydumn); 
    cout << "\n";
    Node* caylechtraimn = taocaylechtrai(dulieu);
    cout << "Cay lech trai: "; 
    incay(caylechtraimn); 
    cout << "\n";
    Node* caylechphaimn = taocaylechphai(dulieu);
    cout << "Cay lech phai: "; 
    incay(caylechphaimn); 
    cout << "\n";
    Node* cayzigzacmn = taocayzigzac(dulieu);
    cout << "Cay zigzac:    "; 
    incay(cayzigzacmn); 
    cout << "\n";

    cout << "\ncay bieu thuc \n";
    string bthauto = "ab+c*"; // Biểu thức mẫu
    cout << "Bieu thuc hau to goc: " << bthauto << "\n";
    Nodebieuthuc* gocbt = taocaybieuthuc(bthauto);
    cout << "1. Duyet truoc (Tien to):  "; 
    duyettruoc(gocbt); 
    cout << "\n";
    cout << "2. Duyet giua  (Trung to): "; 
    duyetgiua(gocbt); 
    cout << "\n";
    cout << "3. Duyet sau   (Hau to):   "; 
    duyetsau(gocbt); 
    cout << "\n";
    return 0;
}