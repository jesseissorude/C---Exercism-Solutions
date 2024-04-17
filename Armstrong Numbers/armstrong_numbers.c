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

/* Code review
Reviewer: alterpatzer

Hello! This is a good solution. The only change that I would consider is at line 15. Instead of picking out digit i by using a power of 10, you could get the digits by repeated division, similar to what you did in the loop on lines 8-11, e.g.,

    n = candidate;
    for (int i = 0; i < digits; i++) {
        int d = n % 10;
        n /= 10;
        sum += pow(d, digits);
    }
This is just a little more efficient and is the more usual way of extracting digits.

Another very minor change would be to move the definition of sum down from line 7 to after line 12, so that it isn't introduced until you are ready to use it. In a short function like this, it doesn't really matter, but in a longer function, it is good practice to define things where you first need them.

Overall, it is a very clean solution. Good work!

...

In the old days, C compilers required you to put all of the definitions at the top, and many people are still in the habit of doing that. I think that it is more readable to wait until you need the definition. If I am in the middle of reading a long function and some variable starts being used that was defined 50 lines earlier, I have to pause and remind myself what its type is and how it was initialized, and also make sure that it hasn't been modified afterwards. It is easier if I can see the definition right there. Of course, it is better not to have long functions in the first place, but it happens frequently.
---

## Actions for me:
- get rid of call to pow() at line 15

*/