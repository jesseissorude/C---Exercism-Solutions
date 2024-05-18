/*  Instructions
Calculate the number of grains of wheat on a chessboard given that the number on each square doubles.

There once was a wise servant who saved the life of a prince. The king promised to pay whatever the servant could dream up. 
Knowing that the king loved chess, the servant told the king he would like to have grains of wheat. 
One grain on the first square of a chess board, with the number of grains doubling on each successive square.

There are 64 squares on a chessboard (where square 1 has one grain, square 2 has two grains, and so on).

Write code that shows:

how many grains were on a given square, and
the total number of grains on the chessboard */

#include <math.h>
#include "grains.h"

uint64_t square(uint8_t index) {
    return pow(2, index-1);
}

uint64_t total(void) {
    int sum = 0;
    for (int i=1; i<=64; i++) {
        sum += square(i);
    }

    return sum;
}
