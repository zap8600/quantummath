#include <iostream>
#include <complex>
#include <vector>

using namespace std::complex_literals;

class Matrix {
    public:
        std::vector<std::complex<double>> m;
        long rows;
        long columns;

        Matrix(long nr, long nc) {
            rows = nr;
            columns = nc;
        }

        void Identity() {
            for(long j = 0; j < rows; j++) {
                m[(j * rows) + j] = 1.0;
            }
        }

        Matrix operator*(Matrix const& right) {
            Matrix result(rows, columns);
        }
};

int main() {
    return 0;
}
