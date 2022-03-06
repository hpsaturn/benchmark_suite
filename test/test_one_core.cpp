#include <Arduino.h>
#include <unity.h>

long primes_time;
long palindromes_time;
float k, j, k1, k2 = 0.0;
int32_t i, n, b, sum = 0;

void test_prime_numbers(void) {
    long primes_init_time = millis();
    for (i = 2; i <= 10000; i++) {
        k = int(sqrt(i)) + 1;
        for (j = 2; j <= k; j++) {
            k1 = i / j;
            k2 = (int32_t) k1;
            if (k1 == k2) {
                break;
            }
        }
        if (k1 != k2) {
            // Serial.print(String(i) + " ");
        }
    }
    primes_time = millis() - primes_init_time;
    
    TEST_ASSERT_EQUAL_INT_MESSAGE(10001, i, "Prime numbers test failed");
}

void test_palindrome_numbers(void) {
    long palindromes_init_time = millis();
    int32_t i;
    for (i = 0; i <= 10000; i++) {
        n = i;
        while (n > 0) {
            // Find reverse of n
            b = n % 10;
            sum = sum * 10 + b;
            n = n / 10;
        }
        // If n and rev are same, n is palindrome number
        if (sum == i) {
            // Serial.print(String(i) + " ");
        }
        sum = 0;
    }

    palindromes_time = millis() - palindromes_init_time;
    TEST_ASSERT_EQUAL_INT_MESSAGE(10001, i, "Palindrome test failed");
}

void setup() {
    delay(2000);  // test service delay
    UNITY_BEGIN();
    Serial.begin(115200);
    Serial.println("\nTEST BOARD "+String(FLAVOR));
    Serial.flush();
    
    RUN_TEST(test_prime_numbers);
    RUN_TEST(test_palindrome_numbers);

    Serial.print("TEST prime numbers\t: ");
    Serial.print(primes_time);
    Serial.println(" miliseconds\n");
    Serial.print("TEST palindrome numbers\t: ");
    Serial.print(palindromes_time);
    Serial.println(" miliseconds\n");
    Serial.print("TEST excution time\t: ");
    Serial.print(palindromes_time + primes_time);
    Serial.println(" miliseconds\n");
    Serial.println("TEST END");

    UNITY_END();
}

void loop() {
}
