#include <stdio.h>
#include <math.h>
#include <complex.h>
// Simulate a quantum computer
// Based on [qc64](https://github.com/dakk/qc64)

// r* are real parts and i* are imagenary parts of the sv
// TODO: Use complex numbers
double complex num0 = 1.0;
double complex num1 = 0.0;
double complex num2 = 0.0;
double complex num3 = 0.0;

void x0() {
    double complex tmp = num0;
    num0 = num1;
    num1 = tmp;

    tmp = num2;
    num2 = num3;
    num3 = tmp;
}

int main() {
    printf("Running X0 gate...\n");
    return 0;
}
