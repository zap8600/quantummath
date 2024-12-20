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
double complex a1 = 0.0;
double complex b0 = 0.0;
double complex b1 = 0.0;

void x0g() {
    a0 = num0;
    num0 = num1;
    num1 = a0;

    a0 = num2;
    num2 = num3;
    num3 = a0;
}

void x1g() {
    a0 = num1;
    num1 = num3;
    num3 = a0;

    a0 = num0;
    num0 = num2;
    num2 = a0;
}

void y0g() {
    num0 = cimag(num0) + (-(creal(num0))) * I;
    num1 = cimag(num1) + (-(creal(num1))) * I;
    num2 = cimag(num2) + (-(creal(num2))) * I;
    num3 = cimag(num3) + (-(creal(num3))) * I;
}

void y1g() {
    num1 = cimag(num1) + (-(creal(num1))) * I;
    num3 = cimag(num3) + (-(creal(num3))) * I;
}

void z0g() {
    num2 = creal(num2) + (-(cimag(num2))) * I;
    num3 = creal(num3) + (-(cimag(num3))) * I;
}

void z1g() {
    num1 = creal(num1) + (-(cimag(num1))) * I;
    num3 = creal(num3) + (-(cimag(num3))) * I;
}

void cxg() {
    a0 = num1;
    num1 = num3;
    num3 = a0;
}

void h0g() {
    a0 = (creal(num0) + creal(num1)) / sqrt(2.0);
    a1 = (cimag(num0) + cimag(num1)) / sqrt(2.0);
    a0 = (creal(num0) - creal(num1)) / sqrt(2.0);
    a1 = (cimag(num0) - cimag(num1)) / sqrt(2.0);
    num0 = a0 + a1 * I;
    num1 = b0 + b1 * I;

    a0 = (creal(num2) + creal(num3)) / sqrt(2.0);
    a1 = (cimag(num2) + cimag(num3)) / sqrt(2.0);
    a0 = (creal(num2) - creal(num3)) / sqrt(2.0);
    a1 = (cimag(num2) - cimag(num3)) / sqrt(2.0);
    num2 = a0 + a1 * I;
    num3 = b0 + b1 * I;
}

void h1g() {
    a0 = (creal(num0) + creal(num2)) / sqrt(2.0);
    a1 = (cimag(num0) + cimag(num2)) / sqrt(2.0);
    a0 = (creal(num0) - creal(num2)) / sqrt(2.0);
    a1 = (cimag(num0) - cimag(num2)) / sqrt(2.0);
    num0 = a0 + a1 * I;
    num1 = b0 + b1 * I;

    a0 = (creal(num1) + creal(num3)) / sqrt(2.0);
    a1 = (cimag(num1) + cimag(num3)) / sqrt(2.0);
    a0 = (creal(num1) - creal(num3)) / sqrt(2.0);
    a1 = (cimag(num1) - cimag(num3)) / sqrt(2.0);
    num2 = a0 + a1 * I;
    num3 = b0 + b1 * I;
}

long z0, z1, z2, z3;

int main() {
    srand(time(0));
    printf("Running gate(s)...\n");
    h0g();
    double sq = pow(creal(num0), 2.0) + pow(cimag(num0), 2) + pow(creal(num1), 2) + pow(cimag(num1), 2) + pow(creal(num2), 2) + pow(cimag(num2), 2) + pow(creal(num3), 2) + pow(cimag(num3), 2);
    if(fabs(sq - 1) > 0.00001) {
        double nf = sqrt(1 / sq);
        num0 *= nf;
        num1 *= nf;
        num2 *= nf;
        num3 *= nf;
    }
    double p0 = pow(creal(num0), 2.0) + pow(cimag(num0), 2.0);
    double p1 = (pow(creal(num1), 2.0) + pow(cimag(num1), 2.0)) + p0;
    double p2 = (pow(creal(num2), 2.0) + pow(cimag(num2), 2.0)) + p1;
    double p3 = (pow(creal(num3), 2.0) + pow(cimag(num3), 2.0)) + p2;

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
        putc('#', stdout);
    }
    putc('\n', stdout);
    printf("01: [ %ld ] ", z2);
    for(int i = 0; i < z2; i++) {
        putc('#', stdout);
    }
    putc('\n', stdout);
    printf("10: [ %ld ] ", z1);
    for(int i = 0; i < z1; i++) {
        putc('#', stdout);
    }
    putc('\n', stdout);
    printf("11: [ %ld ] ", z3);
    for(int i = 0; i < z3; i++) {
        putc('#', stdout);
    }
    putc('\n', stdout);
    return 0;
}
