#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <complex.h>
// Simulate a quantum computer
// Based on [qc64](https://github.com/dakk/qc64)

const int shots = 28;

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

long z0, z1, z2, z3;

int main() {
    srand(time(0));
    printf("Running X0 gate...\n");
    double sq = pow(creal(num0), 2.0) + pow(cimag(num0), 2) + pow(creal(num1), 2) + pow(cimag(num1), 2) + pow(creal(num2), 2) + pow(cimag(num2), 2) + pow(creal(num3), 2) + pow(cimag(num3), 2);
    if(abs(sq - 1) > 0.00001) {
        double nf = sqrt(1 / sq);
        num0 *= nf;
        num1 *= nf;
        num2 *= nf;
        num3 *= nf;
    }
    double p0 = pow(creal(num0), 2.0) + pow(cimag(num0), 2);
    double p1 = (pow(creal(num1), 2.0) + pow(cimag(num1), 2)) + p0;
    double p1 = (pow(creal(num2), 2.0) + pow(cimag(num2), 2)) + p1;
    double p1 = (pow(creal(num3), 2.0) + pow(cimag(num3), 2)) + p2;

    for(int i = 0; i < shots; i++) {
        double r = fmod(((double)(rand()) / (double)(rand())), 1.0);
        
        if(r < p0) {
            z0 += 1;
        } else if((r >= p0) && (r < p1)) {
            z1 += 1;
        } else if((r >= p1) && (r < p2)) {
            z2 += 1;
        } else if((r >= p2) && (r < p3)) {
            z3 += 1;
        }
    }

    printf("00: [ %ld ] ", z0);
    for(int i = 0; i < z0; i++) {
        putc("#");
    }
    putc("\n");
    printf("01: [ %ld ] ", z1);
    for(int i = 0; i < z1; i++) {
        putc("#");
    }
    putc("\n");
    printf("10: [ %ld ] ", z2);
    for(int i = 0; i < z2; i++) {
        putc("#");
    }
    putc("\n");
    printf("11: [ %ld ] ", z3);
    for(int i = 0; i < z3; i++) {
        putc("#");
    }
    putc("\n");
    return 0;
}
