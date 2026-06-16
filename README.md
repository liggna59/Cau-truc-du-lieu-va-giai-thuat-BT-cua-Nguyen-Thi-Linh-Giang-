# CÀI ĐẶT ĐỒ THỊ GIAO THÔNG VÀ THUẬT TOÁN BFS
* **Học phần:** Cấu trúc dữ liệu và Giải thuật
## 1. Đề bài yêu cầu
Cài đặt bài toán mô phỏng đồ thị mạng lưới giao thông gồm 11 tỉnh/thành phố và 13 tuyến đường kết nối. Yêu cầu biểu diễn đồ thị dưới 2 dạng cấu trúc lưu trữ khác nhau: **Ma trận kề** (Mảng hai chiều) và **Danh sách liên kết** (Danh sách kề). Tiến hành duyệt đồ thị theo chiều rộng (BFS) bắt đầu từ đỉnh Hà Nội (HN) và xuất ra trình tự các tỉnh thành được duyệt qua.
### Bảng quy ước định danh hệ thống tỉnh thành:
| STT hệ thống | Ký hiệu trong code | chi so mang | Tên tỉnh / Thành phố |
| :---: | :---: | :---: | :--- |
| 1 | HN | 0 | Hà Nội (Đỉnh xuất phát) |
| 2 | TN | 1 | Thái Nguyên |
| 3 | BN | 2 | Bắc Ninh |
| 4 | BG | 3 | Bắc Giang |
| 5 | UB | 4 | Uông Bí |
| 6 | HP | 5 | Hải Phòng |
| 7 | HD | 6 | Hải Dương |
| 8 | HY | 7 | Hưng Yên |
| 9 | PL | 8 | Phủ Lý |
| 10 | HB | 9 | Hòa Bình |
| 11 | ST | 10 | Sơn Tây |

## 2. Phương pháp cài đặt cấu trúc dữ liệu
Ctrinh gồm 3 cấu trúc chính
### 2.1. Cấu trúc Hàng đợi tự định nghĩa (`struct queue`)
Xây dựng cấu trúc hàng đợi tĩnh:
* `data[V + 1]`: Mảng lưu trữ các chỉ số của đỉnh.
* `dau`, `cuoi`: Hai con trỏ quản lý vị trí nạp (`them`) và rút (`bot`) phần tử theo nguyên lý **FIFO** (First In - First Out).
* `larong()`: Hàm kiểm tra trạng thái rỗng để điều khiển vòng lặp duyệt đồ thị.
### 2.2. Phương pháp lưu trữ 1: Ma trận kề (`struct dothimatranke`)
* Biểu diễn đồ thị bằng một mảng hai chiều `matran[V][V]` cố định kích thước $11 \times 11$.
* Các ô mang giá trị `1` biểu thị giữa hai tỉnh có tuyến đường kết nối đối xứng (Đồ thị vô hướng).
* **Thuật toán BFS:** Quét qua toàn bộ dòng của đỉnh hiện tại trên ma trận để tìm các đỉnh kề chưa thăm.
### 2.3. Phương pháp lưu trữ 2: Danh sách liên kết (`struct dsachke`)
* Sử dụng mảng các con trỏ `dau[V]` quản lý các danh sách liên kết đơn của từng đỉnh thông qua cấu trúc `Node` (`stt`, `link`).
* Khi thêm một cạnh kết nối, chương trình chèn phần tử mới vào đầu danh sách liên kết bằng hàm `themdau()` nhằm tối ưu chi phí thời gian.
* **Thuật toán BFS:** Duyệt tuyến tính qua con trỏ liên kết `temp->link` của đỉnh hiện tại để truy xuất nhanh các đỉnh lân cận.
## 3. Phân tích độ phức tạp thuật toán
Gọi $V$ là số lượng đỉnh ($V = 11$) và $E$ là số lượng cạnh kết nối ($E = 13$). Độ phức tạp của thuật toán duyệt theo chiều rộng (BFS) có sự khác biệt rõ rệt dựa trên cấu trúc lưu trữ được lựa chọn:

### 3.1. Đối với cấu trúc Ma trận kề
* **Độ phức tạp thời gian (Time Complexity):** $\mathcal{O}(V^2)$
  * *Giải thích:* Tại mỗi đỉnh khi lấy ra khỏi hàng đợi, thuật toán bắt buộc phải chạy một vòng lặp `for` có kích thước cố định bằng $V$ để kiểm tra toàn bộ hàng trên ma trận nhằm tìm kiếm các đỉnh kề.
* **Độ phức tạp không gian (Space Complexity):** $\mathcal{O}(V^2)$ dành cho việc khởi tạo mảng hai chiều kích thước $V \times V$.
### 3.2. Đối với cấu trúc Danh sách liên kết (Danh sách kề)
* **Độ phức tạp thời gian (Time Complexity):** $\mathcal{O}(V + E)$
  * *Giải thích:* Thuật toán chỉ duyệt qua các đỉnh thực sự kề với đỉnh hiện tại thông qua các con trỏ liên kết đơn. Tổng số lần duyệt qua các liên kết trên toàn bộ chu trình đúng bằng tổng bậc của các đỉnh ($2E$).
* **Độ phức tạp không gian (Space Complexity):** $\mathcal{O}(V + E)$ do bộ nhớ chỉ cấp phát động cho đúng số lượng đỉnh và số lượng cạnh thực tế tồn tại trên hệ thống giao thông.
