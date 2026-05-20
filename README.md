# Bài Tập Tuần 11: Cấu Trúc Cây Nhị Phân (Binary Tree)
1. **Cấu trúc lưu trữ tuần tự** (Sử dụng mảng/vector).
2. **Cấu trúc lưu trữ móc nối** (Sử dụng con trỏ/Node).
3. **Cây biểu thức** (Sử dụng cấu trúc móc nối và ngăn xếp).
## Cấu trúc file code
* **`btt11.cpp`**: Cài đặt cây nhị phân bằng **Cấu trúc lưu trữ tuần tự**.
* **`btt11_mocnoi.cpp`**: Cài đặt cây nhị phân bằng **Cấu trúc lưu trữ móc nối** và ứng dụng xây dựng **Cây biểu thức**.
Chi tiết:
### 1. Cấu trúc lưu trữ tuần tự (`btt11.cpp`)
Sử dụng mảng (vector) với kích thước `2^n - 1` để cấp phát bộ nhớ và mô phỏng các dạng cây:
- [x] **Cây đầy đủ:** Sử dụng công thức vị trí `2*i + 1` (con trái) và `2*i + 2` (con phải).
- [x] **Cây lệch trái:** Các phần tử chỉ mọc nhánh trái.
- [x] **Cây lệch phải:** Các phần tử chỉ mọc nhánh phải.
- [x] **Cây Zigzac:** Các phần tử mọc xen kẽ `Trái -> Phải -> Trái -> Phải`.
### 2. Cấu trúc lưu trữ móc nối và Cây biểu thức (`btt11_mocnoi.cpp`)
Sử dụng `struct Node` liên kết với nhau bằng con trỏ để cấp phát bộ nhớ động linh hoạt:
- [x] Xây dựng 4 dạng cây cơ bản (Đầy đủ, Lệch trái, Lệch phải, Zigzac) tương tự phần tuần tự.
- [x] **Duyệt cây theo thứ tự giữa (In-order):** `Trái -> Gốc -> Phải`.
- [x] **Cây biểu thức:** Xây dựng cây tự động từ biểu thức hậu tố mẫu `ab+c*` (Sử dụng `stack`).
- [x] Thực hiện 3 phép duyệt tiêu chuẩn trên cây biểu thức:
  - **Duyệt trước (Pre-order):** Sinh ra biểu thức Tiền tố (Prefix).
  - **Duyệt giữa (In-order):** Sinh ra biểu thức Trung tố chuẩn toán học (Infix).
  - **Duyệt sau (Post-order):** Sinh ra biểu thức Hậu tố (Postfix).
## Cài đặt và chạy chương trình
Sử dụng terminal
chạy ktra file btt11.mocnoi.cpp
g++ btt11.cpp -o btt11
.\btt11
chạy ktra file btt11.mocnoi.cpp
g++ btt11_mocnoi.cpp -o btt11_mocnoi
.\btt11_mocnoi