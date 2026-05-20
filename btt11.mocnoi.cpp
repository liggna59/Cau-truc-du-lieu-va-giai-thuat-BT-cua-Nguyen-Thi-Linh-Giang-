// cau truc luu tru moc noi
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int dulieu;
    Node* trai;
    Node* phai;
    Node(int giatri) {
        dulieu = giatri;
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

    return 0;
}