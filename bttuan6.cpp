#include <iostream>
#include <string>
using namespace std;
const float USB_CAPACITY_MB = 32768.0f; // 32GB = 32768 MB
//  Khai báo cấu trúc
struct File {
    string name;
    float sizeMB;
    int timestamp; // Số càng nhỏ: thời gian càng cũ
};
struct Node {
    File data;
    Node* next;
};
// Hàm tạo node mới
Node* createNode(string name, float size, int time) {
    Node* newNode = new Node;
    newNode->data.name = name;
    newNode->data.sizeMB = size;
    newNode->data.timestamp = time;
    newNode->next = nullptr;
    return newNode;
}

