#CẤU TRÚC DỮ LIỆU VÀ GIẢI THUẬT
## Bài toán đồ thị giao thông
### Đề bài
Cài đặt thuật toán tìm đường đi ngắn nhất Dijkstra và cây khung nhỏ nhất Prim, Kruskal cho bài toán đồ thị giao thông, đồng thời in cây khung dưới dạng ma trận đỉnh kề.
## Mô tả chương trình
Chương trình mô phỏng hệ thống giao thông gồm 11 tỉnh/thành phố được biểu diễn dưới dạng đồ thị vô hướng có trọng số.
Các đỉnh gồm:
| STT | Tỉnh/Thành |
|-----|------------|
|0|HN - Hà Nội|
|1|TN - Thái Nguyên|
|2|BN - Bắc Ninh|
|3|BG - Bắc Giang|
|4|UB - Uông Bí|
|5|HP - Hải Phòng|
|6|HD - Hải Dương|
|7|HY - Hưng Yên|
|8|PL - Phủ Lý|
|9|HB - Hòa Bình|
|10|ST - Sơn Tây|
Các cạnh biểu diễn các tuyến đường giao thông và trọng số là khoảng cách giữa các tỉnh.
## Cấu trúc chương trình
Chương trình gồm các thành phần chính:
- Cấu trúc Queue phục vụ thuật toán BFS.
- Đồ thị lưu bằng ma trận kề (`dothimatranke`).
- Đồ thị lưu bằng danh sách liên kết (`dsachke`).
- Thuật toán Dijkstra.
- Thuật toán Prim.
- Thuật toán Kruskal.
## Các thuật toán đã cài đặt
### 1. Dijkstra
Chức năng:
- Tìm đường đi ngắn nhất giữa hai đỉnh.
- Lưu vết đường đi.
- In tổng khoảng cách.
- In đường đi tìm được.
Ví dụ trong chương trình:
HN → HP
### 2. Prim
Chức năng:
- Tìm cây khung nhỏ nhất (Minimum Spanning Tree).
- Tính tổng trọng số của cây khung.
- In cây khung dưới dạng ma trận đỉnh kề.
### 3. Kruskal
Chức năng:
- Sắp xếp các cạnh theo trọng số tăng dần.
- Sử dụng Union-Find đơn giản để tránh chu trình.
- Tìm cây khung nhỏ nhất.
- In cây khung dưới dạng ma trận đỉnh kề.
## Cấu trúc dữ liệu sử dụng
- Mảng
- Ma trận kề
- Danh sách liên kết
- Queue
- DFS
- BFS
- Union-Find 
## Độ phức tạp
| Thuật toán | Độ phức tạp |
|------------|-------------|
|Dijkstra (Ma trận kề)|O(V²)|
|Prim (Ma trận kề)|O(V²)|
|Kruskal|O(E²) (do sắp xếp nổi bọt)|
## Triển khai chương trình
### Biến và cấu trúc dữ liệu
- `V`: Số lượng đỉnh của đồ thị (11 tỉnh/thành phố).
- `tendinh[]`: Lưu tên viết tắt của các tỉnh tương ứng với chỉ số đỉnh.
- `vocung`: Giá trị đại diện cho khoảng cách vô cùng giữa hai đỉnh không có cạnh nối.
- `matran[][]`: Ma trận kề lưu trọng số của đồ thị.
- `dsu[]`, `dsv[]`, `dsw[]`: Ba mảng lần lượt lưu đỉnh đầu, đỉnh cuối và trọng số của từng cạnh trước khi nạp vào đồ thị.
- `queue`: Hàng đợi tự cài đặt dùng cho các thuật toán BFS.
- `Node`, `dsachke`: Cấu trúc danh sách liên kết dùng để biểu diễn đồ thị.
### Các biến trong thuật toán
- `d[]`: Lưu khoảng cách ngắn nhất từ đỉnh nguồn (Dijkstra).
- `luuvet[]`: Lưu đỉnh cha để truy vết và in đường đi.
- `dinhchuacodinh[]`: Đánh dấu các đỉnh chưa được chọn trong Dijkstra.
- `gancan[]`: Lưu trọng số cạnh nhỏ nhất nối một đỉnh với cây khung hiện tại (Prim).
- `cha[]`: Lưu đỉnh cha của mỗi đỉnh trong cây khung.
- `trangthai[]`: Đánh dấu đỉnh đã thuộc cây khung hay chưa.
- `CanhKruskal`: Cấu trúc lưu thông tin một cạnh gồm đỉnh đầu (`u`), đỉnh cuối (`v`) và trọng số (`w`).
- `chataphop[]`: Mảng quản lý các tập hợp trong thuật toán Kruskal (Union-Find).
### Các hàm chính
- `khoitao()`: Khởi tạo đồ thị.
- `themcanh()`: Thêm cạnh có trọng số vào đồ thị.
- `duongdi()`: Truy vết và in đường đi từ mảng `luuvet`.
- `dijkstra()`: Tìm đường đi ngắn nhất.
- `prim()`: Xây dựng cây khung nhỏ nhất bằng thuật toán Prim.
- `kruskal()`: Xây dựng cây khung nhỏ nhất bằng thuật toán Kruskal.
- `timgoc()` và `gop()`: Hai hàm hỗ trợ Union-Find trong Kruskal.
