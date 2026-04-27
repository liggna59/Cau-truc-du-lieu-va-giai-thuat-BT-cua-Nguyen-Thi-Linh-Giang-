#BÀI TẬP CƠ BẢN
### Test case: 
| STT | Kịch bản kiểm thử | Dữ liệu đầu vào | Kết quả thực tế | Trạng thái |
| :-- | :--- | :--- | :--- | :--- |
| 1 | Sắp xếp theo MSSV | 20245, 20242, 20243 | Tự động sắp: 20242, 20243, 20245 | Pass |
| 2 | Chèn sinh viên mới | Thêm SV Quan (20247) | Nằm đúng vị trí cuối danh sách | Pass |
| 3 | Tìm trùng ngày sinh | 20/05/2006 | Liệt kê đúng SV Son và SV Son | Pass |
| 4 | Xóa trùng ngày sinh | Xóa ngày 20/05/2006 | Hai SV trùng bị loại khỏi danh sách | Pass |
#BÀI TẬP NÂNG CAO: BÀI TOÁN JOSEPHUS
## 1. Thiết kế giải thuật
 Mô tả bài toán
* Sử dụng cấu trúc dữ liệu Danh sách liên kết vòng đơn (Circular Singly Linked List) để mô phỏng vòng tròn người chơi.
* Mỗi nút (Node) đại diện cho một người chơi, chứa số thứ tự (`stt`) và con trỏ `next` trỏ đến người ngồi kế tiếp.
* Nút cuối cùng (người thứ N) trỏ về nút đầu tiên (người thứ 1) để khép kín vòng tròn.
 Các bước thực hiện
1. Khởi tạo: Tạo danh sách N phần tử, thực hiện nối vòng.
2. Duyệt luật chơi:
    * Sử dụng con trỏ `htai` (hiện tại) và `truoc` (người đứng trước) để duyệt vòng.
    * Mỗi lượt, di chuyển bộ đôi con trỏ này qua M bước truyền bóng.
    * Thực hiện loại bỏ nút tại vị trí `htai` bằng cách cập nhật `truoc->next = htai->next`.
    * Giải phóng bộ nhớ (`delete`) nút bị loại và lặp lại cho đến khi chỉ còn 1 nút duy nhất.
3. Kết quả: Trả về giá trị `stt` của nút cuối cùng còn sót lại.
## 2. Phân tích độ phức tạp thuật toán (với M=1)
Dựa trên giải thuật đã cài đặt:
* Độ phức tạp thời gian (Time Complexity): $O(N)$. Trong trường hợp M = 1, mỗi lượt chơi con trỏ chỉ di chuyển 1 bước để xác định người bị loại. Thao tác xóa một nút trong danh sách liên kết có chi phí là hằng số $O(1)$. Tổng cộng cần loại bỏ $N-1$ người, do đó tổng thời gian chạy tỉ lệ thuận với $N$.
* Độ phức tạp không gian (Space Complexity): $O(N)$. Cần cấp phát bộ nhớ cho N nút để duy trì danh sách liên kết vòng.
## 3. Test case:
| STT | Loại Test Case | Đầu vào (N, M) | Kết quả thực tế | Trạng thái |
| :-- | :--- | :--- | :--- | :--- |
| 1 | Khớp ví dụ đề bài | N=5, M=1 | Người thắng: 3 | Pass |
| 2 | Trường hợp M = 0 | N=5, M=0 | Người thắng: 5| Pass |
| 3 | Trường hợp M = 2 | N=5, M=2 | Người thắng: 4 | Pass |
| 4 | Trường hợp M = 3 | N=5, M=3 | Người thắng: 1 | Pass |
| 5 | Dữ liệu lớn (N > 100k)| N=100.005, M=1| Phản hồi tức thì | Pass |