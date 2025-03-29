iTM0 – Cảm hứng từ Plants vs Zombies
1. Video thử nghiệm
Tổng hợp ảnh và video chơi: https://drive.google.com/drive/folders/1k_v4R0w-Dl_LVjD0vls-dtQY4kiOEs6X?usp=sharing 
2. Giới thiệu game
a) Giới thiệu chung
b) Chơi game
- Màn hình chính của game: Ảnh 1.
Ấn và “Play” để chơi
- Màn hình sẽ chuyển sang hướng dẫn chơi: Ảnh 2
- Ấn vào màn hình bất kỳ vị trí nào sẽ đến lúc chọn độ khó chơi: Ảnh 3
Dễ: 150 Zombies
Bình thường: 300 Zombies
Khó: 500 Zombies
Ác mộng: 1000 Zombies
- Sau khi chọn chế độ sẽ tiến hành chơi: Ảnh 4
- Khi tiêu diệt được 15 quái sẽ dùng được kỹ năng bùng nổ, khi đó bên góc trái phía trên ở màn hình sẽ xuất hiện: Ảnh 5
Có thể thấy ngay khi chơi: Ảnh 6
Khi đó, chỉ cần bấm SPACE là có thể dùng.
- Khi số lượng Zombies đạt 50, góc dưới bên trái màn hình sẽ xuất hiện: Ảnh 7
Khi đó, ấn E sẽ có thể nâng cấp vũ khí, và hình đó sẽ hiện ra giữa màn hình, tức là nâng cấp vũ khí thành công.
- Nếu thua: Ảnh 8
- Nếu thắng:Ảnh 9
c) Cách chơi: Ảnh 2
Có 5 loại Zombies là: Ảnh 10
3. Nguồn
+ Đồ họa game: 
	Hình nền: Sân cỏ (Plants vs Zombies)
	Các sprite sheets Zombies: Các loại Zombies (Plants vs Zombies)
+ Âm thanh: 
	Nhạc nền: Grasswalk (Plants vs Zombies)
	Âm thanh khi tấn công: Hành động nhảy (Mario)
	Âm thanh kỹ năng bùng nổ: Nhân vật Emilie (Genshin Impact)
4. Sơ qua mã nguồn
1. main (main.cpp)
- Chứa hàm main
2. graphics (graphics.h và graphics.cpp): dùng cho đồ họa, âm thanh
- Là nơi extern các Texture, Music, Chunk, biến, ...
- bool initGraphics(): Khởi tạo tất cả: SDL, renderer, window, texture, music, chunk,...
- void cleanupGraphics(): Giải phóng toàn bộ
3. move (move.h và move.cpp): dùng cho cách thức di chuyển của nhân vật và zombies
- extern các biến liên quan đến hình thức di chuyển
- Dùng class để dễ quản lý Zombies: máu, tọa độ, frame, speed, ...
- void capnhattrangthai (SDL_Event &event, int &trangthai, bool &run): Chia thành các trạng thái của nhân vật tùy theo luồng nhập vào từ nút di chuyển hoặc chuột: Đứng yên, Tấn công, Bùng nổ, Nâng cấp vũ khí, Di chuyển lên, Di chuyển xuống
- void hanhdongnhanvat (): Từng trạng thái bên trên sẽ tương ứng với từng hành động của nhân vật
- void spawnZombie(): Sau một khoảng thời gian bằng nhau sẽ tạo ra ngẫu nhiên 1 trong 5 loại Zombies
- void updateZombies(): Cập nhật frame của Zombies và cho Zombies chuyển động về phía nahan vật. Nếu đạn bắn trúng sẽ trừ máu
- void renderZombies(): Render frame của Zombies lên
4. event (event.h và event.cpp): dùng để quản lí vòng lặp sự kiện
- void chay_menu(): Quản lý mục menu
- void batdauchoi(): Quản lý cửa sổ khi bắt đầu chơi trò chơi
- void chay_win(): Quản lý mục khi thắng
- void chay_lose(): Quản lý mục khi thua
- void chay_huongdan(): Quản lý mục hướng dẫn
- void game(): Quản lí toàn bộ hàm trong main

_______Chúc các bạn chơi game vui vẻ_______








