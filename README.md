# 🤖 Arduino Obstacle Avoiding Robot

Robot mobil 4 roda berbasis Arduino yang dapat menghindari rintangan secara otomatis menggunakan sensor ultrasonik dan servo.

---

## 🚀 Fitur
- Deteksi jarak menggunakan HC-SR04
- Navigasi otomatis (hindari rintangan)
- Servo scanning kiri & kanan
- Kontrol 4 motor DC
- Sistem power menggunakan dual battery 18650

---

## 🧰 Komponen
- Arduino Uno
- L293D Motor Driver
- 4x DC Motor
- Servo MG90S
- HC-SR04 Ultrasonic Sensor
- 2x Battery 18650 (7.4V)
- Switch ON/OFF

---

## 🔌 Wiring

### Ultrasonic
- VCC → 5V
- GND → GND
- TRIG → A1
- ECHO → A0

### Servo
- VCC → 5V
- GND → GND
- Signal → D10

### Motor Driver (L293D)
- IN1 → D2
- IN2 → D3
- IN3 → D4
- IN4 → D7
- ENA → D5
- ENB → D6

### Power
- Battery (+) → Switch → VS L293D
- Battery (-) → GND (common)

---

## ⚙️ Cara Kerja
1. Sensor membaca jarak depan
2. Jika ada halangan:
   - Robot mundur
   - Servo scan kiri & kanan
   - Pilih arah lebih aman
3. Jika aman → maju

---

## ▶️ Cara Menjalankan
1. Upload kode ke Arduino
2. Nyalakan switch
3. Robot berjalan otomatis

---

## 📸 Dokumentasi
Ada pada Docs

---

## 👤 Author
Akmal Azamrudi

---

## ⭐ Notes
Pastikan semua GND terhubung (common ground) agar sistem stabil.
