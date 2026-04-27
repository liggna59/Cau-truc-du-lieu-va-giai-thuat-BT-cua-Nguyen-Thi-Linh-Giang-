//baitapcoban
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
struct Ngay{
    int ngay, thang,nam;
};
struct SinhVien {
    char maSV[8];     
    char hoTen[50];   
    int gioiTinh;     
    Ngay ngaySinh;   
    char diaChi[100]; 
    char lop[12];   
    char khoa[7];
};
struct Node {
    SinhVien data;    
    Node *link;     
};
struct List {
    Node *first;     
    Node *last;       
};
void KhoiTao(List &ListSV) {
    ListSV.first = NULL;
    ListSV.last = NULL;
}
void NhapListSV(List &ListSV) {
    int n;
    cout << "Nhap sluong SV ban dau: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        SinhVien sv; 
        cout << "\nNhap thong tin sinh vien" << i + 1 << " ---" << endl;
        cout << "MSSV "; cin >> sv.maSV;
        cout << "Ho ten: "; cin.ignore(); cin.getline(sv.hoTen, 50);
        cout << "Gioi tinh (1: Nam, 0: Nu): "; cin >> sv.gioiTinh;
        cout << "Ngay sinh (ngay thang nam): "; cin >> sv.ngaySinh.ngay >> sv.ngaySinh.thang >> sv.ngaySinh.nam;
        cout << "Dia chi: "; cin.ignore(); cin.getline(sv.diaChi, 100);
        cout << "Lop: "; cin >> sv.lop;
        cout << "Khoa: "; cin >> sv.khoa;
        Node *newNode = new Node;
        newNode->data = sv;
        newNode->link = NULL;
        if (ListSV.first == NULL) {
            ListSV.first = ListSV.last = newNode;
        } else {
            ListSV.last->link = newNode; 
            ListSV.last = newNode; 
        }
    }
}
void SapXepListSV(List &ListSV) {
    for (Node *i = ListSV.first; i != NULL; i = i->link) {
        for (Node *j = i->link; j != NULL; j = j->link) {
            int k = 0;
            while (i->data.maSV[k] != '\0' && i->data.maSV[k] == j->data.maSV[k]) {
                k++;
            }
            if ((unsigned char)i->data.maSV[k] > (unsigned char)j->data.maSV[k]) {
                SinhVien tam = i->data;
                i->data = j->data;
                j->data = tam;
            }
        }
    }
}
void InListSV(List &ListSV) {
    cout << left << setw(10) << "Ma SV" << setw(25) << "Ho Ten" << setw(15) << "Lop" << endl;
    cout << "-" << endl;
    Node *p = ListSV.first;
    while (p != NULL) {
        cout << left << setw(10) << p->data.maSV 
             << setw(25) << p->data.hoTen 
             << setw(15) << p->data.lop << endl;
        p = p->link;
    }
}
void ThemSV(List &ListSV, SinhVien svienmoi) { 
    Node *newNode = new Node;
    newNode->data = svienmoi;
    newNode->link = NULL;
    if (ListSV.first == NULL) {
        ListSV.first = ListSV.last = newNode;
        return;
    }
    int i = 0; 
        while (svienmoi.maSV[i] != '\0' && svienmoi.maSV[i] == ListSV.first->data.maSV[i]) {
        i++;
    }
        if ((unsigned char)svienmoi.maSV[i] < (unsigned char)ListSV.first->data.maSV[i]) {
        newNode->link = ListSV.first;
        ListSV.first = newNode;
        return;
    }
    Node *htai = ListSV.first;
    Node *trc = NULL;
    while (htai != NULL) {
        int j = 0;
        while (svienmoi.maSV[j] != '\0' && svienmoi.maSV[j] == htai->data.maSV[j]) {
            j++; 
        }   
        if ((unsigned char)svienmoi.maSV[j] < (unsigned char)htai->data.maSV[j]) {
            break;  
        }
        trc = htai;
        htai = htai->link;
    }
    newNode->link = htai;    
        if (trc != NULL) {
        trc->link = newNode;  
        }
    if (htai == NULL) {       
        ListSV.last = newNode; 
    }
}
void InSVCungNgaySinh(List &ListSV) {
    bool timnguoitrungngaysinh = false; 
    for (Node *i = ListSV.first; i != NULL; i = i->link) {
        bool daktra = false;
        for (Node *k = ListSV.first; k != i; k = k->link) {
            if (i->data.ngaySinh.ngay == k->data.ngaySinh.ngay &&i->data.ngaySinh.thang == k->data.ngaySinh.thang &&i->data.ngaySinh.nam == k->data.ngaySinh.nam) {
                daktra = true;
                break;
            }
        }
        if (daktra) continue; 
        bool trungngaysinh = false;
        for (Node *j = i->link; j != NULL; j = j->link) {
            if (i->data.ngaySinh.ngay == j->data.ngaySinh.ngay &&i->data.ngaySinh.thang == j->data.ngaySinh.thang && i->data.ngaySinh.nam == j->data.ngaySinh.nam) {
                                if (!trungngaysinh) {
                    cout << "Sinh vien cung ngay sinh " << i->data.ngaySinh.ngay << "/"<< i->data.ngaySinh.thang << "/" << i->data.ngaySinh.nam << ":" << endl;
                    cout << " + " << i->data.hoTen << " (" << i->data.maSV << ")" << endl;
                    trungngaysinh = true;
                    timnguoitrungngaysinh = true;
                }
                cout << " + " << j->data.hoTen << " (" << j->data.maSV << ")" << endl;
            }
        }
    }
    if (!timnguoitrungngaysinh) {
        cout << "khong tim thay sinh vien cung ngay sinh" << endl;
    }
}
void XoaSVCungNgaySinh(List &ListSV) {
    Node *htai = ListSV.first; 
    while (htai != NULL) {
        bool trungngaysinh = false;
        Node *ktra = htai->link; 
                while (ktra != NULL) {
            if (htai->data.ngaySinh.ngay == ktra->data.ngaySinh.ngay &&htai->data.ngaySinh.thang == ktra->data.ngaySinh.thang &&htai->data.ngaySinh.nam == ktra->data.ngaySinh.nam) {
                trungngaysinh = true;
                break; 
            }
            ktra = ktra->link;
        }
        if (trungngaysinh) {
            Ngay ngayCanXoa = htai->data.ngaySinh;
            Node *tam = ListSV.first;
            Node *truoc = NULL;
            while (tam != NULL) {
                if (tam->data.ngaySinh.ngay == ngayCanXoa.ngay &&tam->data.ngaySinh.thang == ngayCanXoa.thang &&tam->data.ngaySinh.nam == ngayCanXoa.nam) {
                    Node *nutxoa = tam;
                    if (truoc == NULL) { 
                        ListSV.first = tam->link;
                        tam = ListSV.first;
                    } else { 
                        truoc->link = tam->link;
                        tam = truoc->link;
                    } 
                    if (nutxoa == ListSV.last) {
                        ListSV.last = truoc; 
                    }
                    delete nutxoa; 
                } else {
                    truoc = tam;
                    tam = tam->link;
                }
            }
            htai = ListSV.first; 
        } else {
        htai = htai->link;
        }
    }
}