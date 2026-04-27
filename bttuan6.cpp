#include <iostream>
#include <string>
using namespace std;
const float dungluongusb = 32768.0f;
struct File{
    string ten;
    double kthuocteptin;
    int moctgian;
};
struct Node{
    File data;
    Node* next;
};
//Tạo node mới
Node* taoNodemoi(string ten, double kthuocteptin, int moctgian){
    Node* newNode = new Node;
    newNode ->data.ten = ten;
    NewNode -> data.kthuocteptin = kthuocteptin; 
    newNode -> data.moctgian = moctgian;
    newNode->next = nullptr;
    return newNode;
}
// Chèn file thoi tgian
void chentheotgian(Node*& head, string ten, double kthuocteptin, int moctgian){
    Node* newNode = taonodemoi(ten, kthuocteptin, moctgian);
    if(head==nullptr || head->data.moctgian>=newNode->data.moctgian){
        newNode->next = head;
        head=NewNode;
        return;
    }
    Node*htai=head;
    while (htai->next != nullptr&& htai->next->data.moctgian<newNode->data.moctgian){
        htai=htai->next;
    }
    newNode->next=htai->next;
    htai->next=newNode;
}
//Tính tổng dung lượng của các file hiện có 
double tinhtongdungluong(Node*head){
    double tongkthuoc = 0;
    Node*htai=head;
    while (htai != nullptr){
        tongkthuoc += htai->data.kthuocteptin;
        htai=htai->next;
    }
    return tongkthuoc;    
}
void xoaFilenhonhat(Node*&head){
    if(head==nullptr) return;
    Node*minNode=head;
    Node*minPrev=nullptr;
    Node*htai=head;
    Node*prev=nullptr;
    while (htai!=nullptr)
    {
    if(htai->data.kthuocteptin<minNode->data.kthuocteptin)
    {
        minNode=htai;
        minPrev=prev;
    }
    prev=htai;
    htai=htai->next;
    }
    cout<<"-> Tu dong xoa file nho nhat: " << minNode->data.ten<<"(" <<minNode->data.kthuocteptin<<"MB)"<<endl;
    if(minPrev==nullptr)
    {
        head = head->next;
    } else{
        minPrev->next=minNode->next;
    }
    delete minNode;
}
void saoluuUSB(Node*&head)
{
    double kthuochtai = tinhtongdungluong(head);
    cout<<"Tong kthuoc file htai: "<< kthuochtai<<"MB"<<endl;
    while (kthuochtai>dungluongusb)
    {
    cout<<"Canh bao: Vuot qua 32GB, giai phong bo nho..."<<endl;
    xoaFilenhonhat(head);
    kthuochtai=tinhtongdungluong(head);
} 
cout<<"Sao luu thanh cong: Dung luong da dung:"<<kthuochtai<<"MB"<<dungluongusb<<"MB"<<endl; 
}
void inDS(Node*head)
{
    if(head==nullptr)
    {
        cout<<"(DS trong)"<<endl;
        return;
    }
    node* htai=head;
    while (htai!=nullptr)
    {
    cout<<htai->data.moctgian<<"-"<< htai-> data.name<<"()"<<htai->data.kthuocteptin<<"MB"<<endl;
    htai=htai->next;
    } 
}
int main() {
    Node* head = nullptr; 
    int n;
    cout << "CHUONG TRINH SAO LUU USB" << endl;
    cout << "Nhap so luong file ban muon them: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        string ten;
        double kthuocteptin;
        int moctgian;
        cout << "\nNhap thong tin file thu " << i + 1 << ":" << endl;
        cout << " + Ten file: ";
        cin.ignore(); 
        getline(cin, ten);
        cout << " + Dung luong (MB): ";
        cin >> kthuocteptin;
        cout << " + Moc thoi gian: ";
        cin >> moctgian;
        chentheotgian(head, ten, kthuocteptin, moctgian);
    }
    cout << "\nDANH SACH FILE DA NHAP" << endl;
    inDS(head);
    cout << "\nBAT DAU SAO LUU" << endl;
    saoluuUSB(head);
    cout << "\nDANH SACH CON LAI TRONG USB" << endl;
    inDS(head);
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nChuong trinh ket thuc" << endl;
    return 0;
}