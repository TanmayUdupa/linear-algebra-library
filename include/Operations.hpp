#pragma once
#include "Matrix.hpp"

//Matrix addition - uses variadic templates 
//elementwise function takes lambda templates as arguments

// Base case 
template <typename T, int nrows, int ncols>
Matrix<T, nrows, ncols> matrix_add(const Matrix<T, nrows, ncols>& mat) {
    return mat;
}

// Recursive case
template <typename T, int nrows, int ncols, typename... Rest>
Matrix<T, nrows, ncols> matrix_add(const Matrix<T, nrows, ncols>& mat1, const Matrix<T, nrows, ncols>& mat2, const Rest&... rest) {
    Matrix<T, nrows, ncols> result;
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return matrix_add(result, rest...);
}


// Matrix subtraction
template <typename T, int nrows, int ncols>
Matrix<T, nrows, ncols> matrix_subtract(const Matrix<T, nrows, ncols>& mat1, const Matrix<T, nrows, ncols>& mat2) {
    Matrix<T, nrows, ncols> result;

    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }

    return result;
}

// Matrix multiplication
template <typename T, int nrows1, int ncols1, int nrows2, int ncols2>
Matrix<T, nrows1, ncols2> matrix_multiply(const Matrix<T, nrows1, ncols1>& mat1, const Matrix<T, nrows2, ncols2>& mat2) {
    static_assert(ncols1 == nrows2, "Matrix dimensions mismatch for multiplication");

    Matrix<T, nrows1, ncols2> result;

    for (int i = 0; i < nrows1; ++i) {
        for (int j = 0; j < ncols2; ++j) {
            for (int k = 0; k < ncols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    return result;
}

template <typename T, int nrows, int ncols, typename Func>
Matrix<T, nrows, ncols> apply_elementwise(const Matrix<T, nrows, ncols>& matrix, Func&& func) {
    Matrix<T, nrows, ncols> result;
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            result[i][j] = std::forward<Func>(func)(matrix[i][j]);
        }
    }
    return result;
}


template <typename T, int nrows, typename Func>
Vector<T, nrows> apply_elementwise(const Vector<T, nrows>& vector, Func&& func) {
    Vector<T, nrows> result;
    for (int i = 0; i < nrows; ++i) {
        result[i] = std::forward<Func>(func)(vector[i]);
    }
    return result;
}
