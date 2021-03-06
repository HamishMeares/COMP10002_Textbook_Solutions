/*=============================================================================
#     FileName: 6-amicablepair.c
#         Desc: searches amicable pairs until certain point.
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-08-13 02:42:38
=============================================================================*/
#include <stdio.h>
#include <stdlib.h>

int isDivisible(int n, int div);
int sumFactors(int stop, int num);
int isAmicable(int x, int y);
void error(int code);

int
main(int argc, char **argv) {
    int x, y, limit;

    printf("Enter limit integer: ");
    if (scanf("%d", &limit) != 1) {
        error(0);
    }

    if (limit <= 0) {
        error(2);
    }

    x = 1;
    y = 1;
    while (x < limit) {
        if (isAmicable(x,y)) {
            printf("%d and %d are amicable pairs.\n", x, y);
            x++;
            y = 1;
        } else if(y<x-1) { 
            y++;
        } else {
            x++;
            y = 1;
        }
    }

    return 0;
}

int
isAmicable(int x, int y) {
    if (sumFactors(x-1,x) == y && sumFactors(y-1,y) == x && x != y) {
        return 1;
    }
    return 0;
}

int
sumFactors(int stop, int num) {
    /*
     * Calculates sum of factors until 'stop'
     * */
    if (stop == 0) {
        return 0;
    }
    return (isDivisible(num, stop))*stop + sumFactors(stop-1, num);
}

int
isDivisible(int n, int div) {
    if (n == (n / div) * div) {
        return 1;
    }
    return 0;
}

void
error(int code) {
    if (code == 0) {
        printf("Illegal input.");
    } else if(code == 1) {
        printf("unknown error");
    } else if(code == 2) {
        printf("Must be positive value.");
    }

    printf("\n");
    exit(EXIT_FAILURE);
}
