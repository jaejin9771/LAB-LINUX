#include <stdio.h>
#include <stdlib.h>

double divide(int a, int b) {
    if (b == 0) {
        fprintf(stderr, "Division by zero error\n");
        exit(EXIT_FAILURE);
    }
    return (double)a / b;
}
