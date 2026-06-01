#include <iostream>
#include <vector>
using namespace std;
// Cau truc mot nut tren cay
struct node {
    int gtri;
    node* trai;
    node* phai;
    node(int x) {
        gtri = x;
        trai = NULL;
        phai = NULL;
    }
};
