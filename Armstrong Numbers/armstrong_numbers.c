#include "armstrong_numbers.h"
#include <math.h>
bool is_armstrong_number(int candidate) {
    int digits = 0;
    int n = candidate;
    int sum = 0;
    while (n != 0) {
        n /= 10;
        digits++;
    }
    for (int i = 0; i<digits; i++) {
        // isolate digit to get base, raise to num digits, add to sum
        sum += pow((int)(candidate / pow(10, i)) % 10, digits);     
    }
    return sum == candidate;
}