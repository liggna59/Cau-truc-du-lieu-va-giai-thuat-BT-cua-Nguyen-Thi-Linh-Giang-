#include <iostream>
#include <string>

using namespace std;

const float USB_CAPACITY_MB = 32768.0f; // 32GB = 32768 MB

// --- Khai báo cấu trúc ---
struct File {
    string name;
    float sizeMB;
    int timestamp; // Số càng nhỏ: thời gian càng cũ
};

struct Node {
    File data;
    Node* next;
};

// --- Các hàm bổ trợ ---

// Hàm tạo node mới
Node* createNode(string name, float size, int time) {
    Node* newNode = new Node;
    newNode->data.name = name;
    newNode->data.sizeMB = size;
    newNode->data.timestamp = time;
    newNode->next = nullptr;
    return newNode;
}

// Chèn file theo trật tự thời gian (Tăng dần)
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

// Tính tổng kích thước các file trong danh sách
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

    // Tìm node có sizeMB nhỏ nhất và node đứng trước nó
    while (current != nullptr) {
        if (current->data.sizeMB < minNode->data.sizeMB) {
            minNode = current;
            minPrev = prev;
        }
        prev = current;
        current = current->next;
    }

    cout << "  -> He thong tu dong xoa file nho nhat: " << minNode->data.name 
         << " (" << minNode->data.sizeMB << " MB)" << endl;

    // Xóa node khỏi danh sách liên kết
    if (minPrev == nullptr) { // Node nhỏ nhất nằm ở đầu danh sách
        head = head->next;
    } else {
        minPrev->next = minNode->next;
    }
    delete minNode;
}

// Sao lưu vào USB và kiểm tra dung lượng
void backupToUSB(Node*& head) {
    float currentSize = calculateTotalSize(head);
    cout << "\nTong kich thuoc file hien tai: " << currentSize << " MB" << endl;

    while (currentSize > USB_CAPACITY_MB) {
        cout << "Canh bao: Vuot qua 32GB! Dang giai phong bo nho..." << endl;
        removeSmallestFile(head);
        currentSize = calculateTotalSize(head); // Cập nhật lại kích thước sau khi xóa
    }
    cout << "Sao luu thanh cong! Dung luong da dung: " << currentSize << " MB / " << USB_CAPACITY_MB << " MB" << endl;
}

// In danh sách file
void printDirectory(Node* head) {
    if (head == nullptr) {
        cout << "(Danh sach trong)" << endl;
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        cout << "[" << current->data.timestamp << "] " << current->data.name
             << " - " << current->data.sizeMB << " MB" << endl;
        current = current->next;
    }
}

// --- Hàm Main ---
int main() {
    Node* documentDir = nullptr;
    int n;

    cout << "=== CHUONG TRINH QUAN LY FILE SAO LUU USB ===" << endl;
    cout << "Nhap so luong file ban muon them: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        float size;
        int time;

        cout << "\nFile thu " << i + 1 << ":" << endl;
        cout << " + Ten file: ";
        cin.ignore(); // Xóa bộ nhớ đệm
        getline(cin, name);
        cout << " + Dung luong (MB): ";
        cin >> size;
        cout << " + Thoi gian (Timestamp): ";
        cin >> time;

        insertChronological(documentDir, name, size, time);
    }

    cout << "\n--- DANH SACH FILE DA NHAP (Sap xep theo thoi gian) ---" << endl;
    printDirectory(documentDir);

    cout << "\n--- BAT DAU QUA TRINH SAO LUU ---" << endl;
    backupToUSB(documentDir);

    cout << "\n--- DANH SACH FILE CON LAI TRONG USB ---" << endl;
    printDirectory(documentDir);

    // Giải phóng bộ nhớ (Cleanup)
    while (documentDir != nullptr) {
        Node* temp = documentDir;
        documentDir = documentDir->next;
        delete temp;
    }

    cout << "\nDa giai phong bo nho. Ket thuc chuong trinh." << endl;
    return 0;
}