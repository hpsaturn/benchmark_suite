#include <Arduino.h>
#include <unity.h>

float i;
float k;
float j;
float k1;
float k2;
long init_time;
long final_time;

void test_one_core(void) {
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
            // Serial.println(i);
        }
    }
    final_time = millis() - init_time;
    Serial.print(final_time); 
    Serial.println(" miliseconds\n");
    TEST_ASSERT_EQUAL_INT_MESSAGE(10001, i, "One core test failed");
    Serial.println("TEST END");
}

void setup() {
    delay(2000);  // test service delay
    UNITY_BEGIN();
    Serial.begin(115200);
    Serial.println("\nTEST Board\t: "+String(FLAVOR));
    Serial.println("TEST One Core\t: 10000 prime numbers");
    Serial.flush();
    Serial.print("TEST final time\t: ");
    RUN_TEST(test_one_core);
    UNITY_END();
}

void loop() {
}
