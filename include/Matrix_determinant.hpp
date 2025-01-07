#pragma once
#include "Matrix.hpp" 
#include "Vector.hpp"

//This file includes function declarations for Matrix_determinant.cpp

namespace MatrixOperations {

    template <typename T>
    T determinant(const Matrix<T, 2, 2>& mat);

    template <typename T>
    T determinant(const Matrix<T, 1, 1>& mat);

    template <typename T, int N>
    T determinant(const Matrix<T, N, N>& mat);

    template <typename T, int N>
    T determinant(const Matrix<T, N, N>& mat);

    template <typename T, int N, int... M>
    T determinant(const Matrix<T, N, M...>& mat);

    template <typename T, int nrows, int ncols>
    T friend_determinant(const Matrix<T, nrows, ncols>& mat);

} 

