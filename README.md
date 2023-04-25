# ----------------------> CỜ CARO <-------------------------




## Tổng quan
- Game Caro đơn giản với 2 chế độ chơi (người/máy).

## Luật chơi
- 2 người chơi, người đi trước là X, người đi sau là O, 2 người chơi X và O đánh luân phiên nhau. 
- Nếu có 5 dấu (X/O) xếp thành đường ngang hoặc đường dọc hoặc đường chéo thì người chơi (X/O) sẽ chiến thắng. 
- Nếu đã đi hết bàn cờ mà không có người chiến thắng thì kết quả là hòa.

## Cách chơi
- Click chuột vào ô muốn thực hiện nước đi.
- Khi đang trong trận, nhấn phím "**R**" để reset bàn cờ (replay).
- Nhấn phím "**Esc**" (hoặc chọn "**Exit**") để thoát khỏi trò chơi.

## Cài đặt

1. Sao chép link repository trong phần clone.
[![Copy repository link](https://i.postimg.cc/90jkybmD/Screenshot-2023-04-08-095942.png)](https://postimg.cc/HcB3gQ7m)

2. Mở Command Line(Terminal), chuyển đến thư mục chứa repository, dùng lệnh: **cd + path**. <br>Ví dụ: chuyển đến thư mục *F:\LTNC\Clone*
[![Change directory](https://i.postimg.cc/28jbCBhY/Screenshot-2023-04-08-102529.png)](https://postimg.cc/5jGN3ysK)

3. Gõ lệnh **git clone** rồi dán link repository sao chép ở bước 1.
[![Clone repository](https://i.postimg.cc/W1Xxxxjj/Screenshot-2023-04-08-103135.png)](https://postimg.cc/TK5kD7pH)

4. Vào thư mục chứa repository, mở file có đuôi .cbp (project file của CodeBlocks).
[![Open project file](https://i.postimg.cc/Bn742jjx/Screenshot-2023-04-08-103822.png)](https://postimg.cc/3kGsTJCR)

5. Build chương trình và chạy <br>
Phím tắt: **F9 (Build and Run)** hoặc **Ctrl+F9 (Build)** + **Ctrl+F10 (Run)**.




## Môi trường
- Project chạy trên IDE **CodeBlocks (20.03)**.
- Link download: <https://sourceforge.net/projects/codeblocks/>
## Thư viện liên kết
- SDL2
- SDL2_image
- SDL2_ttf
- SDL2_mixer

