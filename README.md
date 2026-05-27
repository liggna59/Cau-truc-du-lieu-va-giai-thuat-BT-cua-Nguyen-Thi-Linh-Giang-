# Bài Tập Tuần 12 - Sắp Xếp Vun Đống (Heap Sort)
## Đề bài: Cài đặt giải thuật sắp xếp vun đống cho các cây ví dụ trong slide và trên bảng, in ra từng trạng thái lưu trữ cho mỗi bước vun đống và sắp xếp 
## Dữ liệu đầu vào
Chương trình chạy thử nghiệm trên 2 tập dữ liệu:
1. **Cây ví dụ trong slide:** `[4, 1, 3, 2, 16, 9, 10, 14, 8, 7]`
2. **Cây ví dụ trên bảng:** `[203, 106, 78, 84, 59, 15, 32, 16, 10, 17, 38, 11]` (da qua vun dong)
Kết quả: 
## Cay trong slide
Mang ban dau: [ 4 1 3 2 16 9 10 14 8 7 ]
Tao dong ban dau
Sau khi vun dong tai node4: [ 4 1 3 2 16 9 10 14 8 7 ]
Sau khi vun dong tai node3: [ 4 1 3 14 16 9 10 2 8 7 ]
Sau khi vun dong tai node2: [ 4 1 10 14 16 9 3 2 8 7 ]
Sau khi vun dong tai node1: [ 4 16 10 14 7 9 3 2 8 1 ]
Sau khi vun dong tai node0: [ 16 14 10 8 7 9 3 2 4 1 ]
Sap xep vun dong 
Hoan vi nut goc  voi mang dang xet[9]: [ 1 14 10 8 7 9 3 2 4 16 ]
Vun dong lai nut goc: [ 14 8 10 4 7 9 3 2 1 16 ]
Hoan vi nut goc  voi mang dang xet[8]: [ 1 8 10 4 7 9 3 2 14 16 ]
Vun dong lai nut goc: [ 10 8 9 4 7 1 3 2 14 16 ]
Hoan vi nut goc  voi mang dang xet[7]: [ 2 8 9 4 7 1 3 10 14 16 ]
Vun dong lai nut goc: [ 9 8 3 4 7 1 2 10 14 16 ]
Hoan vi nut goc  voi mang dang xet[6]: [ 2 8 3 4 7 1 9 10 14 16 ]
Vun dong lai nut goc: [ 8 7 3 4 2 1 9 10 14 16 ]
Hoan vi nut goc  voi mang dang xet[5]: [ 1 7 3 4 2 8 9 10 14 16 ]
Vun dong lai nut goc: [ 7 4 3 1 2 8 9 10 14 16 ]
Hoan vi nut goc  voi mang dang xet[4]: [ 2 4 3 1 7 8 9 10 14 16 ]
Vun dong lai nut goc: [ 4 2 3 1 7 8 9 10 14 16 ]
Hoan vi nut goc  voi mang dang xet[3]: [ 1 2 3 4 7 8 9 10 14 16 ]
Vun dong lai nut goc: [ 3 2 1 4 7 8 9 10 14 16 ]
Hoan vi nut goc  voi mang dang xet[2]: [ 1 2 3 4 7 8 9 10 14 16 ]
Vun dong lai nut goc: [ 2 1 3 4 7 8 9 10 14 16 ]
Hoan vi nut goc  voi mang dang xet[1]: [ 1 2 3 4 7 8 9 10 14 16 ]
Vun dong lai nut goc: [ 1 2 3 4 7 8 9 10 14 16 ]
##  Cay tren bang
Mang ban dau: [ 203 106 78 84 59 15 32 16 10 17 38 11 ]
Tao dong ban dau
Sau khi vun dong tai node5: [ 203 106 78 84 59 15 32 16 10 17 38 11 ]
Sau khi vun dong tai node4: [ 203 106 78 84 59 15 32 16 10 17 38 11 ]
Sau khi vun dong tai node3: [ 203 106 78 84 59 15 32 16 10 17 38 11 ]
Sau khi vun dong tai node2: [ 203 106 78 84 59 15 32 16 10 17 38 11 ]
Sau khi vun dong tai node1: [ 203 106 78 84 59 15 32 16 10 17 38 11 ]
Sau khi vun dong tai node0: [ 203 106 78 84 59 15 32 16 10 17 38 11 ]
Sap xep vun dong 
Hoan vi nut goc  voi mang dang xet[11]: [ 11 106 78 84 59 15 32 16 10 17 38 203 ]
Vun dong lai nut goc: [ 106 84 78 16 59 15 32 11 10 17 38 203 ]
Hoan vi nut goc  voi mang dang xet[10]: [ 38 84 78 16 59 15 32 11 10 17 106 203 ]
Vun dong lai nut goc: [ 84 59 78 16 38 15 32 11 10 17 106 203 ]
Hoan vi nut goc  voi mang dang xet[9]: [ 17 59 78 16 38 15 32 11 10 84 106 203 ]
Vun dong lai nut goc: [ 78 59 32 16 38 15 17 11 10 84 106 203 ]
Hoan vi nut goc  voi mang dang xet[8]: [ 10 59 32 16 38 15 17 11 78 84 106 203 ]
Vun dong lai nut goc: [ 59 38 32 16 10 15 17 11 78 84 106 203 ]
Hoan vi nut goc  voi mang dang xet[7]: [ 11 38 32 16 10 15 17 59 78 84 106 203 ]
Vun dong lai nut goc: [ 38 16 32 11 10 15 17 59 78 84 106 203 ]
Hoan vi nut goc  voi mang dang xet[6]: [ 17 16 32 11 10 15 38 59 78 84 106 203 ]
Vun dong lai nut goc: [ 32 16 17 11 10 15 38 59 78 84 106 203 ]
Hoan vi nut goc  voi mang dang xet[5]: [ 15 16 17 11 10 32 38 59 78 84 106 203 ]
Vun dong lai nut goc: [ 17 16 15 11 10 32 38 59 78 84 106 203 ]
Hoan vi nut goc  voi mang dang xet[4]: [ 10 16 15 11 17 32 38 59 78 84 106 203 ]
Vun dong lai nut goc: [ 16 11 15 10 17 32 38 59 78 84 106 203 ]
Hoan vi nut goc  voi mang dang xet[3]: [ 10 11 15 16 17 32 38 59 78 84 106 203 ]
Vun dong lai nut goc: [ 15 11 10 16 17 32 38 59 78 84 106 203 ]
Hoan vi nut goc  voi mang dang xet[2]: [ 10 11 15 16 17 32 38 59 78 84 106 203 ]
Vun dong lai nut goc: [ 11 10 15 16 17 32 38 59 78 84 106 203 ]
Hoan vi nut goc  voi mang dang xet[1]: [ 10 11 15 16 17 32 38 59 78 84 106 203 ]
Vun dong lai nut goc: [ 10 11 15 16 17 32 38 59 78 84 106 203 ]