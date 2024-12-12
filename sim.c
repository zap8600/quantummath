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
double complex a0 = 0.0;

void x0() {
    a0 = num0;
    num0 = num1;
    num1 = a0;

    a0 = num2;
    num2 = num3;
    num3 = a0;
}

int main() {
    printf("Running X0 gate...\n");
    double sq = pow(creal(num0), 2.0) + pow(cimag(num0), 2) + pow(creal(num1), 2) + pow(cimag(num1), 2) + pow(creal(num2), 2) + pow(cimag(num2), 2) + pow(creal(num3), 2) + pow(cimag(num3), 2);
    if(abs(sq - 1) > 0.00001) {
        double nf = sqrt(1 / sq);
    }
    return 0;
}
