-	Tên trò chơi : Xếp Hình.

-	Tác giả : Đỗ Xuân Dũng.

-	Thời gian hoàn thành : 3 tuần.

-	Luật chơi và giải thích:
&  hiển thị  :
+ void taobang : kẻ khung trò chơi có kích thước 18x10 nhưng thực chất là 22x10 vì 4 hàng đầu tiên dùng để chứa gạch .
+ void trangthaibang : dùng để biểu diễn vị trí của ô trên bảng có gạch khi board[i][j] == 1 in ra kí tự 2 trong bảng mã ASII ;
+void capnhatlaitoado : hàm dùng để xóa hàng khi đầy gạch.
& Thông tin score , level , speed:
+ dùng struct để biểu diễn : 
•	Ban đầu gán giá trị với score = 0  , level = 1 , speed = 0.3.
•	Cập nhật thông tin cho người chơi , khi score đạt đến 200 đ thì level tăng lên một  , và speed giảm đi 0,1.
 & Tạo khối gạch :
+ gán cho mỗi khối gạch một ID riêng . ví dụ : 
	khối gạch thẳng đứng có ma trận arr[4][1] có dãy bit là “1111” thì id = 15
	khối hình vuông có dãy bit là “1111” nhưng để không trùng với hình thẳng đứng thì ta đăị id khối là 31.
	Khối chữ T ta cũng đặt id là 58
	Các khối còn lại id suy ra từ dãy bit.
      &  Luật chơi :
+ nếu vị trí gạch <=3 hoặc score = 300 thì end game.
+ nếu một hàng đầy gạch thì xóa hàng đó đi và người chơi được cộng 20đ và báo hiệu bằng tiếng beep .
&  Hàm main :
+ sử dụng 2 vòng lặp lồng nhau và dùng hàm vẽ và xóa khối gạch để tạo sự chuyển động.
+ dùng hàm clock_t để điều chỉnh tốc độ của gạch rơi.


-	Hướng phát triển trò chơi :
+ Thêm một số hình mới
+ Tạo ra các ải để vượt qua : có thời gian chạy , trong thời gian đó người chơi phải chơi được số điểm yêu cầu mới được chơi tiếp trong ải sau. Các ải càng cao, thời gian chơi càng ít, số điểm cần vượt qua tăng. 
