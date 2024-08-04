#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Alamat I2C dari LCD, bisa bervariasi tergantung modul Anda.
// Alamat umum adalah 0x27 atau 0x3F.
#define I2C_ADDR 0x27

// Buat objek LiquidCrystal_I2C
LiquidCrystal_I2C lcd(I2C_ADDR, 16, 2);  // LCD dengan 16 kolom dan 2 baris

void setup() {
  // Konfigurasi ulang pin I2C
  Wire.setSDA(PB9);
  Wire.setSCL(PB8);

  // Mulai Wire library
  Wire.begin();

  // Inisialisasi LCD
  lcd.init();  // Menginisialisasi LCD

  // Nyalakan lampu latar LCD
  lcd.backlight();

  // Tampilkan pesan awal di LCD
  lcd.setCursor(0, 0);  // Pindah ke kolom 0, baris 0
  lcd.print("UlilGnome, STM32!");
}

void loop() {
  // Pesan yang akan ditampilkan
  String message = " UlilGanteng, STM32! ";

  // Panjang pesan
  int messageLength = message.length();

  // Loop untuk menggeser pesan
  for (int position = 0; position < messageLength; position++) {
    // Hapus baris sebelumnya
    lcd.clear();

    // Set kursor ke awal
    lcd.setCursor(0, 0);

    // Tampilkan pesan mulai dari posisi yang berbeda
    for (int i = 0; i < 16; i++) {
      // Mengambil karakter dengan indeks yang berputar
      char c = message[(position + i) % messageLength];
      lcd.print(c);
    }

    // Tunggu sebelum menggeser lagi
    delay(300);
  }
}
