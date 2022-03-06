

# PlatformIO Benchmark Suite

A benchmark suite is a collection of benchmarks, being a benchmark a test or set of tests used to compare the performance of alternative tools or techniques, here with the help of PlatformIO we have some tests over microcontrollers

## Requeriments

For this first version, should be put the right USB ports of each board. Please edit platformio.ini and add your boards like this:

```python
[env:M5ATOM]
extends = esp32_common
monitor_port = /dev/ttyUSB0
upload_port = /dev/ttyUSB0
test_port = /dev/ttyUSB0
``` 

## Run the tests

Build all tests only:

```bash
pio test --without-uploading --without-testing
```

Test all connected boards:

```bash
pio test
```

Output:

```python
TEST BOARD M5ATOM_DUAL_CORE
TEST prime numbers	: 146 miliseconds
TEST palindrome numbers	: 40 miliseconds
TEST excution time	: 186 miliseconds
TEST END
-----------------------
1 Tests 0 Failures 0 Ignored
=========== [PASSED] Took 7.91 seconds ========

TEST BOARD ESP8266
test_multi_core.cpp:117:test_prime_numbers	[PASSED]
test_multi_core.cpp:118:test_palindrome_numbers	[PASSED]
TEST prime numbers	: 803 miliseconds
TEST palindrome numbers	: 1042 miliseconds
TEST excution time	: 1845 miliseconds
TEST END
-----------------------
2 Tests 0 Failures 0 Ignored
=========== [PASSED] Took 10.08 seconds ========

Test    Environment         Status    Duration
------  ------------------  --------  ------------
*       M5ATOM              PASSED    00:00:10.728
*       M5ATOM_DUAL_CORE    PASSED    00:00:07.911
*       TDISPLAY            PASSED    00:00:07.968
*       TDISPLAY_DUAL_CORE  PASSED    00:00:07.938
*       ESP8266             PASSED    00:00:10.121
======= 5 succeeded in 00:00:44.666 =========
``` 

## Alternative output

```bash
pio test | grep TEST

(master) avp:m5atom_benchmark$ pio test | grep TEST
TEST BOARD M5ATOM
TEST prime numbers	: 146 miliseconds
TEST palindrome numbers	: 40 miliseconds
TEST excution time	: 186 miliseconds
TEST END
TEST BOARD M5ATOM_DUAL_CORE
TEST prime numbers	: 146 miliseconds
TEST palindrome numbers	: 40 miliseconds
TEST excution time	: 186 miliseconds
TEST END
TEST BOARD TDISPLAY
TEST prime numbers	: 147 miliseconds
TEST palindrome numbers	: 40 miliseconds
TEST excution time	: 187 miliseconds
TEST END
TEST BOARD TDISPLAY_DUAL_CORE
TEST prime numbers	: 146 miliseconds
TEST palindrome numbers	: 40 miliseconds
TEST excution time	: 186 miliseconds
TEST END
TEST BOARD ESP8266
TEST prime numbers	: 804 miliseconds
TEST palindrome numbers	: 1042 miliseconds
TEST excution time	: 1846 miliseconds
TEST END
```
