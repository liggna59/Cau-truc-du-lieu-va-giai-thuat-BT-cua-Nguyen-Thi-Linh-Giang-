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
    void dfstimduong(int u, bool datham[], int luuvet[]) {
        datham[u] = true;
        for (int v = 0; v < V; v++) {
            if (matran[u][v] == 1 && !datham[v]) {
                luuvet[v] = u;
                dfstimduong(v, datham, luuvet);
            }
        }
    }
    void timduongbatky(int nguon, int dich) {
        bool datham[V] = {false};
        int luuvet[V];
        for (int i = 0; i < V; i++) luuvet[i] = -1;
        dfstimduong(nguon, datham, luuvet);
        cout << "Duong di bat ky (Ma tran ke): ";
        duongdi(luuvet, nguon, dich);
    }
    void timduongngannhat(int nguon, int dich) {
        bool datham[V] = {false};
        int luuvet[V];
        for (int i = 0; i < V; i++) luuvet[i] = -1;
        queue q; q.khoitao();
        datham[nguon] = true; q.them(nguon);
        while (!q.larong()) {
            int u = q.bot();
            if (u == dich) break;
            for (int v = 0; v < V; v++) {
                if (matran[u][v] == 1 && !datham[v]) {
                    datham[v] = true; luuvet[v] = u; q.them(v);
                }
            }
        }
        cout << "Duong di ngan nhat (Ma tran ke): ";
        duongdi(luuvet, nguon, dich);
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
    void dfstimduong(int u, bool datham[], int luuvet[]) {
        datham[u] = true;
        Node* temp = dau[u];
        while (temp != nullptr) {
            int v = temp->stt;
            if (!datham[v]) {
                luuvet[v] = u;
                dfstimduong(v, datham, luuvet);
            }
            temp = temp->link;
        }
    }
    void timduongbatky(int nguon, int dich) {
        bool datham[V] = {false};
        int luuvet[V];
        for (int i = 0; i < V; i++) luuvet[i] = -1;
        dfstimduong(nguon, datham, luuvet);
        cout << "Duong di bat ky (DSLK): ";
        duongdi(luuvet, nguon, dich);
    }
    void timduongngannhat(int nguon, int dich) {
        bool datham[V] = {false};
        int luuvet[V];
        for (int i = 0; i < V; i++) luuvet[i] = -1;
        queue q; q.khoitao();
        datham[nguon] = true; q.them(nguon);
        while (!q.larong()) {
            int u = q.bot();
            if (u == dich) break;
            Node* temp = dau[u];
            while (temp != nullptr) {
                int v = temp->stt;
                if (!datham[v]) {
                    datham[v] = true; luuvet[v] = u; q.them(v);
                }
                temp = temp->link;
            }
        }
        cout << "Duong di ngan nhat (DSLK): ";
        duongdi(luuvet, nguon, dich);
    }
};
struct tuyenduong {
    int u; 
    int v; 
};
int main() {
    const int tong = 13; 
    tuyenduong dsachduong[tong] = {
        {0, 1}, {0, 2}, {0, 6}, {0, 8}, {0, 9}, {0, 10},
        {2, 3}, {2, 4}, {3, 4}, {4, 5}, {6, 5}, {6, 7}, {8, 7}
    };
    dothimatranke gmatran; 
    gmatran.khoitao(); 
    for (int i = 0; i < tong; i++) {
        gmatran.themcanh(dsachduong[i].u, dsachduong[i].v); 
    }
    gmatran.duyetbfs(0); 
    gmatran.timduongbatky(0, 5);    // Tìm đường HN -> HP
    gmatran.timduongngannhat(0, 5);  // Tìm đường ngắn nhất HN -> HP
    cout << "\n"; 
    dsachke gdsach; 
    gdsach.khoitao(); 
    for (int i = 0; i < tong; i++) { 
        gdsach.themcanh(dsachduong[i].u, dsachduong[i].v); 
    }
    gdsach.duyetbfs(0); 
    gdsach.timduongbatky(0, 5);    // Tìm đường HN -> HP
    gdsach.timduongngannhat(0, 5);  // Tìm đường ngắn nhất HN -> HP
    return 0;
}