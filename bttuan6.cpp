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
Node* taoNodemoi(string ten, double kthuocteptin, int moctgian){
    Node* newNode = new Node;
    newNode ->data.ten = ten;
    NewNode -> data.kthuocteptin = kthuocteptin; 
    newNode -> data.mocthoigian = moctgian;
    newNode->next = nullptr;
    return newNode;
}
