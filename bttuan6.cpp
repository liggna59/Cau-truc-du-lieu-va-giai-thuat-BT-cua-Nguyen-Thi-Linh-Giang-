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
//  Chèn file theo trật tự thời gian
void insertChronological(Node*& head, string name, float size, int time) {
    Node* newNode = createNode(name, size, time);
    // Nếu danh sách rỗng hoặc file mới có thời gian cũ nhất
    if (head == nullptr || head->data.timestamp >= newNode->data.timestamp) {
        newNode->next = head;
        head = newNode;
        return;
    }
    // Duyệt tìm vị trí chèn
    Node* current = head;
    while (current->next != nullptr && current->next->data.timestamp < newNode->data.timestamp) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}
//  Tính tổng kích thước
float calculateTotalSize(Node* head) {
    float totalSize = 0;
    Node* current = head;
    while (current != nullptr) {
       totalSize += current->data.sizeMB;
        current = current->next;
    }
    return totalSize;
}
// Xóa file có kích thước nhỏ nhất
void removeSmallestFile(Node*& head) {
    if (head == nullptr) return;
    Node* minNode = head;
    Node* minPrev = nullptr;
    Node* current = head;
    Node* prev = nullptr;
   // Tìm node nhỏ nhất và node đứng trước nó
    while (current != nullptr) {
        if (current->data.sizeMB < minNode->data.sizeMB) {
            minNode = current;
            minPrev = prev;
        }
        prev = current;
        current = current->next;
    }
    cout << "  -> Da xoa file: " << minNode->data.name << " (" << minNode->data.sizeMB << " MB)" << endl;
   // Xóa node nhỏ nhất khỏi danh sách
    if (minPrev == nullptr) { // Node nhỏ nhất là Head
        head = head->next;
    } else {
        minPrev->next = minNode->next;
    }
    delete minNode;
}

