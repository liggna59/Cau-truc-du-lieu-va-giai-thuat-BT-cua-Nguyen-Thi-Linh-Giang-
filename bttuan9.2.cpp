//baitapnangcao
#include <iostream>
#include <ctime>
using namespace std;
struct Node {
    int stt;
    Node* next;
};
int timNguoiThang(int N, int M) {
    if (N <= 0) return -1;
    if (N == 1) return 1;
    Node* head = new Node{1, NULL};
    Node* htai = head;
    for (int i = 2; i <= N; i++) {
        htai->next = new Node{i, NULL};
        htai = htai->next;
    }
    htai->next = head; 
    Node* truoc = htai; 
    htai = head;
    while (htai->next != htai) { 
        for (int i = 0; i < M; i++) {
            truoc = htai;
            htai = htai->next;
        }
        truoc->next = htai->next;
        Node* tam = htai;
        htai = htai->next; 
        delete tam;
    }
    int kq = htai->stt;
    delete htai;
    return kq;
}
int main() {
    int n, m;
    cout << "--- BAI TOAN JOSEPHUS ---" << endl;
    cout << "Nhap so nguoi choi (N): "; 
    cin >> n;
    cout << "Nhap so buoc truyen bong (M): "; 
    cin >> m;
    cout << "\nBat dau tro choi..." << endl;
    int winner = timNguoiThang(n, m);
    cout << "\n=> Nguoi chien thang cuoi cung la: " << winner << endl;
    return 0;
}