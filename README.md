# esp32-s3-Anggoro-redi-saputro-3223600014
Matakuliah Sistem Embedded konsep multitasking dan dual-core processing pada mikrokontroler ESP32-S3
Anggoro redi saputro - 3223600014 - 3 D4 Teknik Komputer A

pin yang di gunakan
____________________________________________________
| Komponen           | Pin ESP32-S3 | Keterangan   |
| ------------------ | ------------ | ------------ |
| LED                | 15           | Output       |
| Buzzer             | 4            | Output       |
| Push Button 1      | 18           | Input        |
| Push Button 2      | 19           | Input        |
| Potensiometer      | 36           | Analog input |
| OLED SDA           | 8            | I2C data     |
| OLED SCL           | 9            | I2C clock    |
| Rotary Encoder CLK | 10           | Input A      |
| Rotary Encoder DT  | 11           | Input B      |
| Rotary Encoder SW  | 12           | Push switch  |
| Servo PWM          | 42           | Output PWM   |
| Stepper B-         | 37           | Output coil  |
| Stepper B+         | 38           | Output coil  |
| Stepper A+         | 39           | Output coil  |
| Stepper A-         | 40           | Output coil  |
____________________________________________________

Penjelasan Fungsi xTaskCreatePinnedToCore()
Fungsi ini adalah bagian penting dari FreeRTOS yang digunakan untuk membuat task baru dan menentukan core mana yang akan menjalankannya.
xTaskCreatePinnedToCore(function_name,task_name,stack_size,task_parameter,priority,task_handle,core_ID);


Contoh : xTaskCreatePinnedToCore(taskLED, "taskLED_Core0", 1000, NULL, 1, NULL, 0);


Perbedaan Core 0 dan Core 1
| Core       | Fungsi Utama                            | Keterangan                                                  |
| ---------- | --------------------------------------- | ----------------------------------------------------------- |
| **Core 0** | Sistem, Wi-Fi, Bluetooth, task tambahan | Dapat digunakan untuk tugas rutin atau proses berat         |
| **Core 1** | Program utama (Arduino loop, setup)     | Biasanya digunakan untuk task utama seperti UI, sensor      |

Kesimpulan

Dengan FreeRTOS, ESP32-S3 dapat menjalankan beberapa proses (task) secara bersamaan di dua core.
Fungsi xTaskCreatePinnedToCore() memungkinkan pembagian kerja antar-core secara manual.
Pembagian tugas yang baik (misalnya LED di Core 0 dan sensor di Core 1) dapat meningkatkan performa sistem dan membuat respon lebih cepat.


