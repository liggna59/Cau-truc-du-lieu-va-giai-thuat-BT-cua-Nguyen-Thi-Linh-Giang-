# CÀI ĐẶT ĐỒ THỊ GIAO THÔNG VÀ CÁC THUẬT TOÁN DUYỆT, TÌM ĐƯỜNG
* **Học phần:** Cấu trúc dữ liệu và Giải thuật (Tuần 15)
## 1. Đề bài yêu cầu
Mô phỏng đồ thị mạng lưới giao thông gồm 11 tỉnh/thành phố và 13 tuyến đường kết nối. Yêu cầu biểu diễn đồ thị dưới 2 dạng cấu trúc lưu trữ khác nhau: **Ma trận kề** (Mảng hai chiều) và **Danh sách liên kết** (Danh sách kề). 
Tiến hành cài đặt:
1. Duyệt đồ thị theo chiều rộng (BFS) bắt đầu từ đỉnh Hà Nội (HN).
2. Tìm đường đi bất kỳ giữa 2 tỉnh thành (Sử dụng thuật toán DFS).
3. Tìm đường đi ngắn nhất giữa 2 tỉnh thành (Sử dụng thuật toán BFS trên đồ thị không trọng số).
### Bảng quy ước định danh hệ thống tỉnh thành:
| STT hệ thống | Ký hiệu trong code | Chỉ số mảng | Tên tỉnh / Thành phố |
| :---: | :---: | :---: | :--- |
| 1 | HN | 0 | Hà Nội (Đỉnh xuất phát) |
| 2 | TN | 1 | Thái Nguyên |
| 3 | BN | 2 | Bắc Ninh |
| 4 | BG | 3 | Bắc Giang |
| 5 | UB | 4 | Uông Bí |
| 6 | HP | 5 | Hải Phòng (Đích kiểm thử) |
| 7 | HD | 6 | Hải Dương |
| 8 | HY | 7 | Hưng Yên |
| 9 | PL | 8 | Phủ Lý |
| 10 | HB | 9 | Hòa Bình |
| 11 | ST | 10 | Sơn Tây |
## 2. Phương pháp cài đặt cấu trúc dữ liệu
Chương trình bao gồm 2 modul chính:
### 2.1. Cấu trúc Hàng đợi tự định nghĩa (`struct queue`)
Xây dựng cấu trúc hàng đợi tĩnh để phục vụ cho thuật toán duyệt BFS và tìm đường đi ngắn nhất:
* `data[V + 1]`: Mảng lưu trữ các chỉ số của đỉnh.
* `dau`, `cuoi`: Hai con trỏ quản lý vị trí nạp (`them`) và rút (`bot`) phần tử theo nguyên lý **FIFO** (First In - First Out).
### 2.2. Cơ chế lưu vết và In lộ trình ngược (`void duongdi`)
* Thuật toán sử dụng một mảng `luuvet[V]` được khởi tạo bằng `-1`. Khi đi từ đỉnh `u` sang đỉnh `v`, ta lưu lại dấu vết bằng lệnh: `luuvet[v] = u`.
* Khi chạm tới Đích, hàm `duongdi` sẽ truy vết ngược dựa trên các giá trị lưu trong mảng từ Đích về Nguồn, đẩy vào một mảng tạm `path[V]` rồi thực hiện in xuôi chiều để cho ra lộ trình dạng: `HN -> HD -> HP`.
### 2.3. Phương pháp lưu trữ 1: Ma trận kề (`struct dothimatranke`)
* Biểu diễn đồ thị bằng một mảng hai chiều `matran[V][V]` cố định kích thước $11 \times 11$.
* **Tìm đường bất kỳ (DFS):** Sử dụng đệ quy, liên tục đi sâu vào đỉnh kề đầu tiên chưa thăm của đỉnh hiện tại.
* **Tìm đường ngắn nhất (BFS):** Sử dụng `queue` tự chế, loang đều theo từng tầng khoảng cách. Vì đồ thị không có trọng số, đường đi đầu tiên chạm tới đích đảm bảo là đường đi qua ít cạnh nhất.
### 2.4. Phương pháp lưu trữ 2: Danh sách liên kết (`struct dsachke`)
* Sử dụng mảng các con trỏ `dau[V]` quản lý các danh sách liên kết đơn thông qua cấu trúc `Node` (`stt`, `link`).
* **Thuật toán tìm đường (DFS/BFS):** Thay vì dùng vòng lặp duyệt qua các chỉ số từ $0 \rightarrow V-1$ như ma trận kề, cấu trúc này sử dụng con trỏ tạm `Node* temp = dau[u]` và vòng lặp tuyến tính `temp = temp->link` để chỉ quét qua đúng các đỉnh thực sự có đường nối, tăng tốc độ xử lý.
## 3. Phân tích độ phức tạp thuật toán
Gọi $V$ là số lượng đỉnh ($V = 11$) và $E$ là số lượng cạnh kết nối ($E = 13$).
### 3.1. Đối với cấu trúc Ma trận kề
* **Độ phức tạp thời gian (Time Complexity):** * Duyệt BFS: $\mathcal{O}(V^2)$
  * Tìm đường DFS / BFS: $\mathcal{O}(V^2)$ do mỗi lần xét một đỉnh, thuật toán phải dùng vòng lặp duyệt qua toàn bộ dòng $V$ phần tử để tìm đỉnh kề.
* **Độ phức tạp không gian (Space Complexity):** $\mathcal{O}(V^2)$ dành cho việc khởi tạo mảng hai chiều kích thước $V \times V$.
### 3.2. Đối với cấu trúc Danh sách liên kết
* **Độ phức tạp thời gian (Time Complexity):** $\mathcal{O}(V + E)$
  * Do thuật toán chỉ truy cập trực tiếp vào các nút kề thực tế thông qua con trỏ liên kết, không tốn chi phí duyệt các ô trống mang giá trị `0` như ma trận kề.
* **Độ phức tạp không gian (Space Complexity):** $\mathcal{O}(V + E)$ bộ nhớ cấp phát động tương ứng đúng với số lượng đỉnh và số lượng cạnh thực tế tồn tại.
