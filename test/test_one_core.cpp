#include <Arduino.h>
#include <unity.h>


long init_time;
long primes_time;
long palindromes_time;

void test_prime_numbers(void) {
    float i, k, j, k1, k2;
    long primes_init_time = millis();
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
    primes_time = millis() - primes_init_time;
    Serial.print("TEST prime numbers\t: ");
    Serial.print(primes_time);
    Serial.println(" miliseconds\n");
    TEST_ASSERT_EQUAL_INT_MESSAGE(10001, i, "Prime numbers test failed");
}

void test_palindrome_numbers(void) {
    long palindromes_init_time = millis();
    int i, n, b, rev = 0;
    for (i = 0; i <= 10000; i++) {
        n = i;
        while (n > 0) {
            // Find reverse of n
            b = n % 10;
            rev = rev * 10 + b;
            n = n / 10;
        }
        // If n and rev are same, n is palindrome number
        if (rev == i) {
            // Serial.println(i + " ");
        }
        rev = 0;
    }

    palindromes_time = millis() - palindromes_init_time;
    Serial.print("TEST palindrome numbers\t: ");
    Serial.print(palindromes_time);
    Serial.println(" miliseconds\n");
    TEST_ASSERT_EQUAL_INT_MESSAGE(10001, i, "Palindrome test failed");
}

void setup() {
    delay(2000);  // test service delay
    UNITY_BEGIN();
    Serial.begin(115200);
    Serial.println("\nTEST BOARD "+String(FLAVOR));
    Serial.flush();
    init_time = millis();
    RUN_TEST(test_prime_numbers);
    // RUN_TEST(test_palindrome_numbers);
    Serial.print("TEST excution time\t: ");
    Serial.print(palindromes_time + primes_time);
    Serial.println(" miliseconds\n");
    Serial.println("TEST END");
    UNITY_END();
}

void loop() {
}
