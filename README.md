# 🤖 Obstacle Avoiding Robot (Arduino)

Robot mobil 4 roda berbasis Arduino yang dapat menghindari rintangan menggunakan sensor ultrasonik dan servo.

## 🚀 Fitur
- Deteksi jarak menggunakan HC-SR04
- Menghindari rintangan secara otomatis
- Servo scanning kiri & kanan
- Kontrol motor menggunakan L298N / Motor Shield

## 🧰 Komponen
- Arduino Uno
- Motor Driver (L298N / Adafruit Motor Shield)
- 4x DC Motor
- Servo Motor
- Ultrasonic Sensor (HC-SR04)
- Bluetooth HC-05 (opsional)

## ⚙️ Cara Kerja
1. Sensor ultrasonik membaca jarak
2. Jika ada objek dekat:
   - Robot mundur
   - Scan kiri & kanan
   - Pilih arah dengan jarak lebih luas
3. Jika aman → maju

## 🔌 Wiring
(Lampirkan gambar di folder docs)

## ▶️ Cara Menjalankan
1. Upload file `.ino` ke Arduino
2. Nyalakan robot
3. Robot akan berjalan otomatis

## 📸 Dokumentasi
Tambahkan foto robot di folder `docs`

## 👤 Author
Nama kamu
