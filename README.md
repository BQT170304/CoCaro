# --------> Tic Tac Toe <--------




## Tổng quan
- Game Caro 3x3(Tic Tac Toe) đơn giản với 2 chế độ chơi (người/máy).
- Cách chơi: Click chuột vào ô để đánh nước muốn đi.
## Luật chơi
- 2 người chơi, người đi trước là X, người đi sau là O, 2 người chơi X và O đánh luân phiên nhau. 
- Nếu có 3 dấu (X/O) xếp thành đường ngang hoặc đường dọc hoặc đường chéo thì người chơi (X/O) sẽ chiến thắng. 
- Nếu đã đi hết 9 ô mà không có người chiến thắng thì kết quả là hòa.

## Cài đặt

1. Sao chép link repository trong phần clone.
[![Copy_repo_link.png](https://i.postimg.cc/90jkybmD/Screenshot-2023-04-08-095942.png)](https://postimg.cc/HcB3gQ7m)

2. Mở Command Line(Terminal), chuyển đến thư mục chứa repository, dùng lệnh: cd + path.
Ví dụ: chuyển đến thư mục F:\LTNC\Clone
[![Screenshot-2023-04-08-102529.png](https://i.postimg.cc/28jbCBhY/Screenshot-2023-04-08-102529.png)](https://postimg.cc/5jGN3ysK)

3. Gõ lệnh git clone rồi dán link repository sao chép ở bước 1.
[![Screenshot-2023-04-08-103135.png](https://i.postimg.cc/W1Xxxxjj/Screenshot-2023-04-08-103135.png)](https://postimg.cc/TK5kD7pH)

4. Vào thư mục chứa repository, mở file có đuôi .cbp (project file của CodeBlocks).
[![Screenshot-2023-04-08-103822.png](https://i.postimg.cc/Bn742jjx/Screenshot-2023-04-08-103822.png)](https://postimg.cc/3kGsTJCR)

5. Build chương trình và chạy (F9 hoặc Ctrl F9 + Ctrl F10).




## Môi trường và thư viện
1. Project chạy trên IDE CodeBlocks.
2. Thư viện cần thiết:
- SDL2
- SDL2_image
- SDL2_ttf
- SDL2_mixer

