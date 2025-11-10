#define BTN 19
#define LED 15

void taskButton(void *pvParameters) {
  while (1) {
    int state = digitalRead(BTN);
    digitalWrite(LED, !state);
    delay(50);
  }
}

void setup() {
  pinMode(BTN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  //core 0
  xTaskCreatePinnedToCore(taskButton, "Button_Task", 2000, NULL, 1, NULL, 0);
  //core 1
  //xTaskCreatePinnedToCore(taskButton, "Button_Task", 2000, NULL, 1, NULL, 1);
}
void loop() {}
