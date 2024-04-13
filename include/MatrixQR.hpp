#include "Matrix.hpp"

template<typename T, int nrows, int ncols>
class MatrixQR {
private:
    Matrix<T, nrows, ncols> Q;
    Matrix<T, ncols, ncols> R;

    T custom_sqrt(T value) {
        T epsilon = static_cast<T>(0.0001);  // Adjust epsilon based on precision requirements
        T guess = value / static_cast<T>(2);
        T diff = guess * guess - value;

        while (diff > epsilon || diff < -epsilon) {
            guess = (guess + value / guess) / static_cast<T>(2);
            diff = guess * guess - value;
        }

        return guess;
    }

public:
    MatrixQR(const Matrix<T, nrows, ncols>& A) {
        // Initialize Q and R matrices
        Q = Matrix<T, nrows, ncols>();
        R = Matrix<T, ncols, ncols>();

        Matrix<T, nrows, ncols> A_copy = A;  // Make a copy of A to avoid modifying original matrix

        for (int k = 0; k < ncols; ++k) {
            T norm = 0;
            for (int i = k; i < nrows; ++i) {
                norm += A_copy[i][k] * A_copy[i][k];
            }
            norm = custom_sqrt(norm);  // Use custom_sqrt function
            R[k][k] = norm;

            for (int i = k; i < nrows; ++i) {
                Q[i][k] = A_copy[i][k] / norm;
            }

            for (int j = k + 1; j < ncols; ++j) {
                T dot_product = 0;
                for (int i = k; i < nrows; ++i) {
                    dot_product += A_copy[i][j] * Q[i][k];
                }
                R[k][j] = dot_product;

                for (int i = k; i < nrows; ++i) {
                    A_copy[i][j] -= dot_product * Q[i][k];
                }
            }
        }
    }

    Matrix<T, nrows, ncols> getQ() const {
        return Q;
    }

    Matrix<T, ncols, ncols> getR() const {
        return R;
    }
};
