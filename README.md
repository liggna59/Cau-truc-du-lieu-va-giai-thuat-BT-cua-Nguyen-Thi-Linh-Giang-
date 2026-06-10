# BÁO CÁO BÀI TẬP TUẦN 14 - CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT
* **Học phần:** Cấu trúc dữ liệu và Giải thuật
* **Nhiệm vụ:** Cài đặt Cây tìm kiếm nhị phân tự cân bằng (AVL Tree)
## 1. Đề bài 
> Cài đặt cây cân bằng AVL với đầu vào là dãy số sau, thực hiện các thêm và duyệt cây để in ra giá trị của các phần tử trên cây.
> 
| | | | | | | | | |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **32** | **51** | **27** | **83** | **96** | **11** | **45** | **75** | **66** |
| **1** | **2** | **3** | **4** | **5** | **6** | **7** | **8** | **9** |
## 2. cài đặt cấu trúc dữ liệu
### 2.1. Cấu trúc dữ liệu nút (`struct Node`)
Mỗi nút trên cây AVL được quản lý bởi các thành phần:
* `so`: Trường dữ liệu kiểu số nguyên lưu giá trị khóa (key) của nút.
* `trai`, `phai`: Con trỏ liên kết trỏ tới nút con bên trái và nút con bên phải.
* `cao`: Biến lưu trữ chiều cao hiện thời của nút, làm cơ sở toán học để tính toán hệ số cân bằng.
### 2.2. Các hàm xử lý cân bằng hệ thống
Cây AVL duy trì tính cân bằng nhờ vào các kỹ thuật xoay nút ngay sau khi thực hiện chèn dữ liệu:
* `cao(Node *N)`: Trả về thông tin chiều cao để tránh lỗi truy cập vùng nhớ khi gặp nút rỗng (`NULL`).
* `laycbang(Node *N)`: Tính toán độ chênh lệch chiều cao giữa hai nhánh (`Chiều cao nhánh trái - Chiều cao nhánh phải`).
* `xoayphai(Node *y)` & `xoaytrai(Node *x)`: Tái cấu trúc liên kết cục bộ khi cây rơi vào trạng thái mất cân bằng (hệ số vượt quá phạm vi $[-1, 1]$).
Thuật toán nhận diện và xử lý triệt để 4 trường hợp mất cân bằng bao gồm: *Trái - Trái*, *Phải - Phải*, *Trái - Phải*, và *Phải - Trái*.
### 2.3. Các phương thức duyệt cây
Triển khai 2 phương thức duyệt đệ quy để kiểm tra tính đúng đắn của cây:
1. `duyetgiua(Node *goc)` (In-order Traversal): Xuất dữ liệu theo thứ tự tăng dần để chứng minh tính chất của Cây tìm kiếm nhị phân.
2. `duyettruoc(Node *goc)` (Pre-order Traversal): Xuất dữ liệu theo thứ tự từ gốc xuống lá để chứng minh cấu trúc cây đã tự động xoay cân bằng một cách chính xác.
## 3. Đánh giá độ phức tạp thuật toán
Nhờ việc duy trì hệ số cân bằng liên tục sau mỗi thao tác chèn, chiều cao $h$ của cây AVL luôn được khống chế ở mức tỷ lệ thuận với giá trị $\log n$ (với $n$ là tổng số phần tử).
* **Độ phức tạp thời gian chèn (Insertion Time Complexity):** $\mathcal{O}(\log n)$ do chi phí tìm kiếm vị trí chèn và thực hiện các phép xoay hằng số $\mathcal{O}(1)$.
* **Độ phức tạp bộ nhớ (Space Complexity):** $\mathcal{O}(n)$ dùng để cấp phát lưu trữ cho $n$ nút trong hệ thống.
