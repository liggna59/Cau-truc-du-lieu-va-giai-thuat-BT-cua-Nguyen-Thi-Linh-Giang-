

## 1. Phân tích sơ bộ bài toán
Yêu cầu bài toán là xây dựng hệ thống quản lý tập tin trong thư mục `D>Document` bằng cấu trúc dữ liệu **Danh sách liên kết đơn (Singly Linked List)**, đảm bảo các tính chất về thời gian và giới hạn dung lượng lưu trữ.

### Tại sao sử dụng Danh sách liên kết đơn?
* **Tính linh hoạt:** Thao tác chèn file mới (Copy-Paste) và loại bỏ file nhỏ nhất (Backup) được thực hiện liên tục. DSLK giúp cấp phát và giải phóng bộ nhớ động tối ưu hơn mảng tĩnh.
* **Cơ chế hoạt động:** Mỗi file là một `Node`, danh sách luôn được duy trì theo thứ tự tăng dần của `timestamp`.


## 2. Mô tả thuộc tính và cấu trúc dữ liệu

### A. Cấu trúc dữ liệu File
Mỗi tập tin được định nghĩa bởi cấu trúc `struct File` gồm:
- `name` (string): Tên của tập tin.
- `sizeMB` (float): Kích thước tập tin tính bằng Megabytes.
- `timestamp` (int): Nhãn thời gian (số càng nhỏ thời gian càng cũ).

### B. Cấu trúc Danh sách (Node)
Mỗi nút trong danh sách liên kết gồm:
- `data`: Chứa thông tin của một đối tượng `File`.
- `next`: Con trỏ `Node*` lưu địa chỉ của phần tử kế tiếp.

### 3. Mô tả các hàm thực thi chính

`createNode`: Khởi tạo Node mới và cấp phát bộ nhớ bằng toán tử `new`. 
 `insertChronological` : Chèn file vào danh sách sao cho luôn đảm bảo trật tự thời gian. 
 `calculateTotalSize` :Duyệt danh sách để tính tổng dung lượng hiện có của thư mục. 
 `removeSmallestFile` : Tìm và xóa Node có `sizeMB` thấp nhất khỏi bộ nhớ bằng toán tử `delete`. 
 `backupToUSB`:  Kiểm soát dung lượng thư mục không vượt quá hằng số `USB_CAPACITY_MB` (32768 MB). 


## 4. Phân tích giải thuật chi tiết

### 4.1. Giải thuật Chèn theo thời gian (`insertChronological`)
Để duy trì danh sách luôn có thứ tự, giải thuật thực hiện:
1. **Bước 1:** Nếu danh sách rỗng hoặc `timestamp` của file mới nhỏ hơn nút `head`, chèn file mới làm `head`.
2. **Bước 2:** Nếu không, dùng con trỏ `current` duyệt từ đầu danh sách.
3. **Bước 3:** Tìm vị trí sao cho `current->next->timestamp` lớn hơn `timestamp` của file mới.
4. **Bước 4:** Thực hiện chèn vào giữa: `newNode->next = current->next; current->next = newNode;`.
### 4.2. Giải thuật Xóa file nhỏ nhất (`removeSmallestFile`)
Sử dụng giải thuật tìm giá trị cực tiểu trên danh sách liên kết:
1. Duyệt qua toàn bộ danh sách, sử dụng biến `minNode` để ghi nhớ địa chỉ Node có `sizeMB` nhỏ nhất.
2. Sử dụng con trỏ `minPrev` để lưu lại nút đứng trước nút nhỏ nhất.
3. Sau khi kết thúc vòng lặp, thực hiện nối nút `minPrev` với `minNode->next` để tách nút nhỏ nhất khỏi chuỗi liên kết.
4. Giải phóng bộ nhớ của `minNode` bằng lệnh `delete`.

### 4.3. Giải thuật Sao lưu vào USB (`backupToUSB`)
* **Logic:** Kiểm tra điều kiện `totalSize > 32768`.
* **Thực thi:** Chừng nào tổng dung lượng còn vượt ngưỡng, hệ thống tự động gọi hàm `removeSmallestFile`. Đây là chiến lược loại bỏ file chiếm ít không gian nhất để tối ưu hóa số lượng file còn lại trong USB.

## 5. Hướng dẫn cài đặt
1. Biên dịch mã nguồn: `g++ bttuan6.cpp -o bttuan6.exe`
