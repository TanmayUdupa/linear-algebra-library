#include "Matrix_determinant.hpp"

//Variadic template used for rectangular matrix
//Template specialisation attempted for 1x1 and 2x2 matrix, 1x1 not working because it is a vector

namespace MatrixOperations {

    // Specialisation for 2x2 matrix
    template <typename T>
    T determinant(const Matrix<T, 2, 2>& mat) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }

    // Specialisation for 1x1 matrix - not working because it is a vector with one element
    template <typename T>
    T determinant(const Matrix<T, 1, 1>& mat) {
        return mat[0][0];
    }

//Recursive for square matrices
template <typename T, int N>
T determinant(const Matrix<T, N, N>& mat) {
    T result = 0;
    if constexpr (N == 1) {
        result = mat[0][0];
    }
     else {
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

//Variadic used for rectangular matrices
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

} 

