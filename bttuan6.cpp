#include <iostream>
#include <string>
using namespace std;
const float dungluongusb = 32768.0f;
struct File{
    string ten;
    double kthuocteptinh;
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
    newNode -> data.mocthoigian = moctgian;
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
    if(htai->data.kthuocteptin<minNode->data.kthuocteptinh)
    {
        minNode=htai;
        minPrev=prev;
    }
    prev=htai;
    htai=htai->next;
    }
    cout<<"-> Tu dong xoa file nho nhat: " << minNode->data.ten<<"(" <<minNode->data.kthuocteptinh<<"MB)"<<endl;
    if(minPrev=nullptr)
    {
        head = head->next;
    } else{
        minPrev->next=minNode->next;
    }
    delete minNode;
}
