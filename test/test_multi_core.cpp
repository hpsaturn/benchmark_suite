#include <Arduino.h>
#include <unity.h>

#define PRIME_ITERATIONS 10000
#define PALIN_ITERATIONS 100000

#define PRIME_RESULT 1228
#define PALIN_RESULT 1099

long primes_time = 0;
long palindromes_time = 0;

int32_t getPrimeNumbers(int32_t n) {
    long primes_init_time = millis();
    int32_t i, count = 0;
    float k, j;
    float k1 = 0.0;
    float k2 = 0.0;
    for (i = 2; i <= n; i++) {
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
            count++;
        }
    }
    primes_time = millis() - primes_init_time;
    return count; 
}

int32_t getPalindromeNumbers(int32_t range) {
    long palindromes_init_time = millis();
    int32_t i, n, b, count = 0;
    int32_t sum = 0;
    for (i = 0; i <= range; i++) {
        n = i;
        while (n > 0) {
            b = n % 10;
            sum = sum * 10 + b;
            n = n / 10;
        }
        // If n and rev are same, n is palindrome number
        if (sum == i) {
            // Serial.print(String(i) + " ");
            count++;
        }
        sum = 0;
    }
    palindromes_time = millis() - palindromes_init_time;
    return count;
}

void test_prime_numbers(void) {
    int32_t prime_numbers = getPrimeNumbers(PRIME_ITERATIONS);
    TEST_ASSERT_EQUAL_INT_MESSAGE(PRIME_RESULT, prime_numbers, "Prime numbers test failed");
}

void test_palindrome_numbers(void) {
    int32_t pal_numbers = getPalindromeNumbers(PALIN_ITERATIONS);
    TEST_ASSERT_EQUAL_INT_MESSAGE(PALIN_RESULT, pal_numbers, "Palindrome test failed");
}


#ifdef DUAL_CORE

TaskHandle_t tHandlePrimes;
TaskHandle_t tHandlePalindromes;

void task_primes(void *pvParameters) {
    test_prime_numbers();
    vTaskDelete(NULL);
}

void task_palindromes(void *pvParameters) {
    test_palindrome_numbers();
    vTaskDelete(NULL);
}

void setupTasks(void) {
    xTaskCreatePinnedToCore(task_primes, "task_primes", 10000, NULL, 1, &tHandlePrimes, 0);
    xTaskCreatePinnedToCore(task_palindromes, "task_palindromes", 10000, NULL, 1, &tHandlePalindromes, 1);
}

void test_dual_core(void) {
    setupTasks();
    while(primes_time == 0 || palindromes_time == 0) {
        delay(10);
    }
}
#endif

void printResults(void) {
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
}

void setup() {
    delay(2000);  // test service delay
    UNITY_BEGIN();
    Serial.begin(115200);
    Serial.println("\nTEST BOARD "+String(FLAVOR));
    Serial.flush();

    #ifdef DUAL_CORE
    RUN_TEST(test_dual_core);
    #else
    RUN_TEST(test_prime_numbers);
    RUN_TEST(test_palindrome_numbers);
    #endif
    printResults();
    UNITY_END();
    
}

void loop() {
}
