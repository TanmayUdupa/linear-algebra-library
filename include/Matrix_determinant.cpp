#include "Matrix_determinant.hpp"

namespace MatrixOperations {

    // Implementation of determinant2x2 for 2x2 matrix
    template <typename T>
    T determinant2x2(const Matrix<T, 2, 2>& mat) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    // Base case: determinant of 1x1 matrix
    template <typename T>
    T determinant(const Matrix<T, 1, 1>& mat) {
        return mat[0][0];
    }

// Recursive case for determinant calculation (NxN matrix)
template <typename T, int N>
T determinant(const Matrix<T, N, N>& mat) {
    T result = 0;
    if constexpr (N == 1) {
        result = mat[0][0];
    } else if constexpr (N == 2) {
        result = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    } else {
        for (int col = 0; col < N; ++col) {
            Matrix<T, N - 1, N - 1> submatrix;
            for (int i = 1; i < N; ++i) {
                for (int j = 0, k = 0; j < N; ++j) {
                    if (j != col) {
                        submatrix[i - 1][k++] = mat[i][j];
                    }
                }
            }
            T cofactor = (col % 2 == 0) ? mat[0][col] : -mat[0][col];
            result += cofactor * determinant(submatrix);
        }
    }
    return result;
}

template <typename T, int N, int... M>
T determinant(const Matrix<T, N, M...>& mat) {
    T result = 0;
    if constexpr (N == 1) {
        result = mat[0][0];
    } else if constexpr (N == 2) {
        result = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    } else {
        for (int col = 0; col < N; ++col) {
            Matrix<T, N - 1, M...> submatrix;
            for (int i = 1; i < N; ++i) {
                for (int j = 0, k = 0; j < N; ++j) {
                    if (j != col) {
                        submatrix[i - 1][k++] = mat[i][j];
                    }
                }
            }
            T cofactor = (col % 2 == 0) ? mat[0][col] : -mat[0][col];
            result += cofactor * determinant(submatrix);
        }
    }
    return result;
}

}  // End of namespace MatrixOperations

// Explicit instantiation for double and N=3 (optional)
// template double MatrixOperations::determinant(const Matrix<double, 3, 3>& mat);

