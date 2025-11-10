#define CLK 10
#define DT 11
#define SW 12

int counter = 0;
int lastState;

void taskEncoder(void *pvParameters) {
  while (1) {
    int current = digitalRead(CLK);
    if (current != lastState) {
      if (digitalRead(DT) != current) counter++;
      else counter--;
      Serial.println(counter);
    }
    lastState = current;
    delay(5);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  lastState = digitalRead(CLK);

  // Core 0
  xTaskCreatePinnedToCore(taskEncoder, "taskEncoder_Core0", 2000, NULL, 1, NULL, 0);

  // Core 1
  // xTaskCreatePinnedToCore(taskEncoder, "taskEncoder_Core1", 2000, NULL, 1, NULL, 1);
}

void loop() {}

