Hiểu ý bạn rồi, mình sẽ điều chỉnh lại nội dung README.md sao cho chuẩn theo đúng cấu trúc chuyên sâu, phân tích kỹ thuật mà bạn mong muốn. Với format này, nhìn vào sẽ thấy ngay tư duy giải thuật mạch lạc của một kỹ sư tương lai.

Bạn copy nội dung dưới đây vào file README.md nhé:

📂 Quản lý Thư mục Document và Sao lưu USB (Linked List)
Dự án triển khai hệ thống quản lý tập tin trong thư mục mô phỏng bằng cấu trúc dữ liệu Danh sách liên kết đơn (Singly Linked List), giải quyết bài toán sắp xếp theo thời gian và tối ưu hóa không gian lưu trữ khi sao lưu.

1. Phân tích sơ bộ bài toán
Yêu cầu bài toán là xây dựng hệ thống quản lý tập tin đảm bảo các tính chất về thời gian và giới hạn dung lượng lưu trữ (32GB).

Tại sao sử dụng Danh sách liên kết đơn?
Tính linh hoạt: Thao tác chèn file mới (Copy-Paste) và loại bỏ file nhỏ nhất (Backup) được thực hiện liên tục. DSLK giúp cấp phát và giải phóng bộ nhớ động tối ưu hơn mảng tĩnh, tránh lãng phí tài nguyên.

Cơ chế hoạt động: Mỗi file là một Node, danh sách luôn được duy trì theo thứ tự tăng dần của timestamp.

2. Mô tả thuộc tính và cấu trúc dữ liệu
A. Cấu trúc dữ liệu File
Mỗi tập tin được định nghĩa bởi cấu trúc struct File gồm:

ten (string): Tên của tập tin.

kthuocteptin (double): Kích thước tập tin tính bằng Megabytes.

moctgian (int): Nhãn thời gian (số càng nhỏ thời gian càng cũ).

B. Cấu trúc Danh sách (Node)
Mỗi nút trong danh sách liên kết gồm:

data: Chứa thông tin của một đối tượng File.

next: Con trỏ Node* lưu địa chỉ của phần tử kế tiếp.

3. Mô tả các hàm thực thi chính
taoNodemoi: Khởi tạo Node mới và cấp phát bộ nhớ bằng toán tử new.

chentheotgian: Chèn file vào danh sách sao cho luôn đảm bảo trật tự thời gian tăng dần.

tinhtongdungluong: Duyệt toàn bộ danh sách để tính tổng dung lượng hiện có của thư mục.

xoaFilenhonhat: Tìm và xóa Node có kthuocteptin thấp nhất khỏi bộ nhớ bằng toán tử delete.

saoluuUSB: Kiểm soát dung lượng thư mục không vượt quá hằng số dungluongusb (32768 MB).

4. Phân tích giải thuật chi tiết
4.1. Giải thuật Chèn theo thời gian (chentheotgian)
Để duy trì danh sách luôn có thứ tự, giải thuật thực hiện:

Bước 1: Nếu danh sách rỗng hoặc moctgian của file mới nhỏ hơn nút head, chèn file mới làm head.

Bước 2: Nếu không, dùng con trỏ htai duyệt từ đầu danh sách.

Bước 3: Tìm vị trí sao cho htai->next->moctgian lớn hơn moctgian của file mới.

Bước 4: Thực hiện chèn vào giữa: newNode->next = htai->next; htai->next = newNode;.

4.2. Giải thuật Xóa file nhỏ nhất (xoaFilenhonhat)
Sử dụng giải thuật tìm giá trị cực tiểu trên danh sách liên kết:

Duyệt qua toàn bộ danh sách, sử dụng biến minNode để ghi nhớ địa chỉ Node có kthuocteptin nhỏ nhất.

Sử dụng con trỏ minPrev để lưu lại nút đứng trước nút nhỏ nhất nhằm phục vụ việc nối lại chuỗi.

Sau khi kết thúc vòng lặp, thực hiện nối nút minPrev với minNode->next để tách nút nhỏ nhất khỏi chuỗi liên kết.

Giải phóng bộ nhớ của minNode bằng lệnh delete.

4.3. Giải thuật Sao lưu vào USB (saoluuUSB)
Logic: Kiểm tra điều kiện tongDungLuong > 32768.

Thực thi: Chừng nào tổng dung lượng còn vượt ngưỡng, hệ thống tự động gọi hàm xoaFilenhonhat. Đây là chiến lược loại bỏ file chiếm ít không gian nhất để tối ưu hóa số lượng file còn lại có thể lưu trữ trong USB.
