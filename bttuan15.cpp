#include <iostream>  
using namespace std; 
const int V = 11; // Tổng số 11 tỉnh thành trong hệ thống giao thông
// Chỉ số mảng: 0->HN, 1->TN, 2->BN, 3->BG, 4->UB, 5->HP, 6->HD, 7->HY, 8->PL, 9->HB, 10->ST
const char* tendinh[V] = {"HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST"};
struct queue {
    int data[V + 1]; 
    int dau;                 // Vị trí đầu hàng đợi (để lấy phần tử ra)
    int cuoi;                // Vị trí cuối hàng đợi (để thêm phần tử vào)
    void khoitao() {
        dau = 0;
        cuoi = 0;
    }
    bool larong() {
        return dau == cuoi; 
    }
    void them(int gtri) {
        data[cuoi] = gtri;
        cuoi++;
    }
    int bot() {
        int gtridau = data[dau];
        dau++;
        return gtridau;
    }
};
void duongdi(int luuvet[], int bdau, int kthuc) {
    if (luuvet[kthuc] == -1) {
        cout << "Khong co duong di tu " << tendinh[bdau] << " den " << tendinh[kthuc] << "\n";
        return;
    }
    int path[V];
    int count = 0;
    int hientai = kthuc;
    while (hientai != -1) {
        path[count++] = hientai;
        hientai = luuvet[hientai];
    }
    for (int i = count - 1; i >= 0; i--) {
        cout << tendinh[path[i]];
        if (i > 0) cout << " -> ";
    }
    cout << "\n";
}
//ĐỒ THỊ LƯU TRỮ BẰNG MA TRẬN KỀ (MẢNG HAI CHIỀU)
struct dothimatranke {
    int matran[V][V]; 
    void khoitao() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                matran[i][j] = 0; 
            }
        }
    }
    void themcanh(int u, int v) {
        matran[u][v] = 1; // Có đường từ u sang v
        matran[v][u] = 1; // Có đường từ v về u
    }
    // Hàm duyệt đồ thị theo chiều rộng (BFS) từ một tỉnh bất kỳ
    void duyetbfs(int bdau) {
        bool datham[V]; // mang trang thai
        for (int i = 0; i < V; i++) {
            datham[i] = false; 
        }
        queue q;
        q.khoitao();
        datham[bdau] = true; // Đánh dấu đã thăm tỉnh xuất phát (Hà Nội)
        q.them(bdau);    
        cout << "Ket qua BFS (Ma tran ke): ";
        while (!q.larong()) {
            int u = q.bot(); 
            cout << tendinh[u] << " -> "; 
            for (int v = 0; v < V; v++) {
                if (matran[u][v] == 1 && !datham[v]) {
                    datham[v] = true; 
                    q.them(v);  
                }
            }
        }
        cout << "END\n";
    }
};
// ĐỒ THỊ LƯU TRỮ BẰNG DANH SÁCH LIÊN KẾT
struct Node {
    int stt; // Lưu mã số của tỉnh kề (từ 0 đến 10)
    Node* link; 
};
struct dsachke {
    Node* dau[V]; 
    void khoitao() {
        for (int i = 0; i < V; i++) {
            dau[i] = nullptr; 
        }
    }
    void themdau(int u, int v) {
        Node* newnode = new Node;      
        newnode->stt = v;      
        newnode->link = dau[u];   
        dau[u] = newnode;          
    }
    void themcanh(int u, int v) {
        themdau(u, v);
        themdau(v, u); 
    }
    void duyetbfs(int bdau) {
        bool datham[V];
        for (int i = 0; i < V; i++) {
            datham[i] = false;
        }
        queue q;
        q.khoitao();
        datham[bdau] = true; 
        q.them(bdau);    
        cout << "Ket qua BFS (Danh sach lien ket): ";
        while (!q.larong()) {
            int u = q.bot(); 
            cout << tendinh[u] << " -> ";
            Node* temp = dau[u]; 
            while (temp != nullptr) { 
                int v = temp->stt; 
                if (!datham[v]) {    
                    datham[v] = true;
                    q.them(v);     
                }
                temp = temp->link; 
            }
        }
        cout << "END\n";
    }
};
struct tuyenduong {
    int u; 
    int v; 
};
int main() {
    const int tong = 13; // Sơ đồ gthong có 13 đường nối (D1 đến D13)
        tuyenduong dsachduong[tong] = {
        {0, 1},  // HN (0) nối với TN (1) -> Đường D7 
        {0, 2},  // HN (0) nối với BN (2) -> Đường D8    
        {0, 6},  // HN (0) nối với HD (6) -> Đường D1    
        {0, 8},  // HN (0) nối với PL (8) -> Đường D4    
        {0, 9},  // HN (0) nối với HB (9) -> Đường D5    
        {0, 10}, // HN (0) nối với ST (10)-> Đường D6    
        {2, 3},  // BN (2) nối với BG (3) -> Đường D9    
        {2, 4},  // BN (2) nối với UB (4) -> Đường D11    
        {3, 4},  // BG (3) nối với UB (4) -> Đường D10    
        {4, 5},  // UB (4) nối với HP (5) -> Đường D12    
        {6, 5},  // HD (6) nối với HP (5) -> Đường D13    
        {6, 7},  // HD (6) nối với HY (7) -> Đường D2    
        {8, 7}   // PL (8) nối với HY (7) -> Đường D3    
    };
    dothimatranke gmatran; 
    gmatran.khoitao(); 
    for (int i = 0; i < tong; i++) {
        gmatran.themcanh(dsachduong[i].u, dsachduong[i].v); 
    }
    gmatran.duyetbfs(0); 
    cout << " "; 
    dsachke gdsach; 
    gdsach.khoitao(); 
    for (int i = 0; i < V; i++) {
        gdsach.themcanh(dsachduong[i].u, dsachduong[i].v); 
    }
    gdsach.duyetbfs(0); 
    return 0;
}