#define BUZZER 4

void taskBuzzer(void *pvParameters) {
  while (1) {
    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);
    delay(200);
  }
}

void setup() {
  pinMode(BUZZER, OUTPUT);
  //core0
  xTaskCreatePinnedToCore(taskBuzzer, "Buzzer_Task", 1000, NULL, 1, NULL, 0);
 //core1
//xTaskCreatePinnedToCore(taskBuzzer, "Buzzer_Task", 1000, NULL, 1, NULL, 1);
}
void loop() {}
