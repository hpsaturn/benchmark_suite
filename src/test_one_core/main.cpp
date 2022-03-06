#include <Arduino.h>

float i;
float k;
float j;
float k1;
float k2;
long init_time;
long final_time;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println();
  Serial.println("Test One Core\t: 10000 prime numbers");
  Serial.flush();
  Serial.print("Test final time\t: ");
  init_time = millis();
  for (i = 2; i <= 10000; i++) {
    k = int(sqrt(i)) + 1;
    for (j = 2; j <= k; j++) {
      k1 = i / j;
      k2 = int(k1);
      if (k1 == k2) {
        break;
      }
    }
    if (k1 != k2) {
      //Serial.println(i);
    }
  }
  final_time = millis() - init_time;
  Serial.print(final_time);
  Serial.println(" miliseconds");
}

void loop() {

}
