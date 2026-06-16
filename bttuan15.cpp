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
        return gia_tri_dau;
    }
};
// CẤU TRÚC 1: ĐỒ THỊ LƯU TRỮ BẰNG MA TRẬN KỀ (MẢNG HAI CHIỀU)
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
        ma_tran[u][v] = 1; // Có đường từ u sang v
        ma_tran[v][u] = 1; // Có đường từ v về u
    }
    // Hàm duyệt đồ thị theo chiều rộng (BFS) từ một tỉnh bất kỳ
    void duyetbfs(int tinh_bat_dau) {
        bool datham[V]; // mang trang thai
        for (int i = 0; i < V; i++) {
            datham[i] = false; 
        }
        queue q;
        q.khoitao();
        datham[bdau] = true; // Đánh dấu đã thăm tỉnh xuất phát (Hà Nội)
        q.them(bdau);    
        cout << "Ket qua BFS: ";
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
