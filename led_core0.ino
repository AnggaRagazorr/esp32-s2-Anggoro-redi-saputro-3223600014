#define LED_PIN 15

void taskLED(void *pvParameters) {
  while (1) {
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(500);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  xTaskCreatePinnedToCore(taskLED, "LED_Task", 1000, NULL, 1, NULL, 0); 
  
}
void loop() {}

