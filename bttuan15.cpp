#include <iostream>  
using namespace std; 
const int V = 11; // Tổng số 11 tỉnh thành trong hệ thống giao thông
// Chỉ số mảng: 0->HN, 1->TN, 2->BN, 3->BG, 4->UB, 5->HP, 6->HD, 7->HY, 8->PL, 9->HB, 10->ST
const char* tendinh[V] = {"HN", "TN", "BN", "BG", "UB", "HP", "HD", "HY", "PL", "HB", "ST"};
const int vocung = 999999;
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
                if ( i== j) matran[i][j] = 0; 
                else
                matran[i][j] = vocung; 
            }
        }
    }
    void themcanh(int u, int v, int w = 1) {
        matran[u][v] = w; // Có đường từ u sang v
        matran[v][u] = w; // Có đường từ v về u
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
    void dijkstra(int nguon, int dich) {
        int d[V];        // duong di ngan nhat tu nguon
        bool dinhchuacodinh[V]; 
        int luuvet[V];  
        for (int i = 0; i < V; i++) {
            d[i] = vocung; dinhchuacodinh[i] = true; luuvet[i] = -1;
        }
        d[nguon] = 0;
        for (int step = 0; step < V - 1; step++) {
            int u = -1; int dmin = vocung;
            for (int i = 0; i < V; i++) {
                if (dinhchuacodinh[i] && d[i] < dmin) { dmin = d[i]; u = i; }
            }
            if (u == -1 || u == dich) break;
            dinhchuacodinh[u] = false;
            for (int v = 0; v < V; v++) {
                if (matran[u][v] != vocung && dinhchuacodinh[v]) {
                    if (d[v] > d[u] + matran[u][v]) {
                        d[v] = d[u] + matran[u][v]; luuvet[v] = u;
                    }
                }
            }
        }
        cout << "Duong di ngan nhat tu (Thuat toan Dijkstra) " << tendinh[nguon] << " den " << tendinh[dich] << " (Tong: " << d[dich];
        if (d[dich] == vocung) { cout << "Khong co duong di\n";
             return; }
        duongdi(luuvet, nguon, dich);
    }
    void prim() {
        int gancan[V]; int cha[V]; bool trangthai[V];
        for (int i = 0; i < V; i++) { gancan[i] = vocung; trangthai[i] = false; cha[i] = -1; }
        gancan[0] = 0;
        int matranmst[V][V];
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) matranmst[i][j] = 0;
        int tongtrongso = 0;
        for (int step = 0; step < V; step++) {
            int u = -1; int min_gancan = vocung;
            for (int i = 0; i < V; i++) {
                if (!trangthai[i] && gancan[i] < min_gancan) { min_gancan = gancan[i]; u = i; }
            }
            if (u == -1) break;
            trangthai[u] = true; tongtrongso += min_gancan;
            if (cha[u] != -1) {
                matranmst[cha[u]][u] = matran[cha[u]][u]; matranmst[u][cha[u]] = matran[cha[u]][u];
            }
            for (int v = 0; v < V; v++) {
                if (matran[u][v] != vocung && !trangthai[v] && matran[u][v] < gancan[v]) {
                    gancan[v] = matran[u][v]; cha[v] = u;
                }
            }
        }
        cout << "\nCay khung nho nhat (Thuat toan Prim)" << " Tong chieu dai MST (Prim): " << tongtrongso;
        for (int i = 0; i < V; i++) cout << tendinh[i] << "  ";
        cout << "\n";
        for (int i = 0; i < V; i++) {
            cout << tendinh[i] << "  ";
            for (int j = 0; j < V; j++) {
                if (matranmst[i][j] == 0) cout << "0   ";
                else {
                    if (matranmst[i][j] < 10) cout << matranmst[i][j] << "   ";
                    else if (matranmst[i][j] < 100) cout << matranmst[i][j] << "  ";
                    else cout << matranmst[i][j] << " ";
                }         
               }
            cout << "\n";
        }
    }
    struct CanhKruskal { int u, v, w; };
    int timgoc(int cha[], int i) {
        while (cha[i] != -1) i = cha[i];
        return i;
    }
    void gop(int cha[], int x, int y) { cha[x] = y; }
    void kruskal(int tongsocanh, int dsu[], int dsv[], int dsw[]) {
        CanhKruskal dscanh[50];
        for (int i = 0; i < tongsocanh; i++) {
            dscanh[i].u = dsu[i]; dscanh[i].v = dsv[i]; dscanh[i].w = dsw[i];
        }
        for (int i = 0; i < tongsocanh - 1; i++) {
            for (int j = 0; j < tongsocanh - i - 1; j++) {
                if (dscanh[j].w > dscanh[j+1].w) {
                    CanhKruskal temp = dscanh[j]; dscanh[j] = dscanh[j+1]; dscanh[j+1] = temp;
                }
            }
        }
        int chataphop[V]; for (int i = 0; i < V; i++) chataphop[i] = -1;
        int matrankruskal[V][V];
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) matrankruskal[i][j] = 0;
        int tongtrongso = 0; int dem_canh_mst = 0;
        for (int i = 0; i < tongsocanh; i++) {
            if (dem_canh_mst == V - 1) break;
            int x = timgoc(chataphop, dscanh[i].u);
            int y = timgoc(chataphop, dscanh[i].v);
            if (x != y) {
                matrankruskal[dscanh[i].u][dscanh[i].v] = dscanh[i].w;
                matrankruskal[dscanh[i].v][dscanh[i].u] = dscanh[i].w;
                tongtrongso += dscanh[i].w; dem_canh_mst++;
                gop(chataphop, x, y);
            }
        }
        cout << "\nCay khung nho nhat (thuat toan Krruskal) \n"<< "Tong chieu dai MST: " << tongtrongso;
        for (int i = 0; i < V; i++) cout << tendinh[i] << "  ";
        cout << "\n";
        for (int i = 0; i < V; i++) {
            cout << tendinh[i] << "  ";
            for (int j = 0; j < V; j++) {
                if (matrankruskal[i][j] == 0) cout << "0   ";
                else {
                    if (matrankruskal[i][j] < 10) cout << matrankruskal[i][j] << "   ";
                    else if (matrankruskal[i][j] < 100) cout << matrankruskal[i][j] << "  ";
                    else cout << matrankruskal[i][j] << " ";
                }
            }
            cout << "\n";
        }
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
    int dsu[tong] = {0, 0, 0, 0, 0, 0,  2, 2, 3, 4, 6, 6, 8}; // dinh nguon
    int dsv[tong] = {1, 2, 6, 8, 9, 10, 3, 4, 4, 5, 5, 7, 7}; // dinh dich
    int dsw[tong] = {75, 31, 57, 58, 76, 42, 15, 105, 90, 45, 45, 28, 33}; //khoang cach 
    dothimatranke gmatran; 
    gmatran.khoitao(); 
    for (int i = 0; i < tong; i++) {
        gmatran.themcanh(dsu[i], dsv[i], dsw[i]); // Nạp cạnh kèm trọng số
    }
    // 1. Tìm đường đi ngắn nhất bằng Dijkstra từ Hà Nội (0) đi Hải Phòng (5)
    gmatran.dijkstra(0, 5); 
    // 2. Tìm và xuất ma trận đỉnh kề của cây khung nhỏ nhất (MST) theo Prim
    gmatran.prim(); 
    // 3. Tìm và xuất ma trận đỉnh kề của cây khung nhỏ nhất (MST) theo Kruskal
    gmatran.kruskal(tong, dsu, dsv, dsw); 
    return 0;
}