#pragma once
#include "Matrix.hpp"

//This file includes function declarations for Matrix_transpose.cpp

namespace MatrixOperations {

    template <typename T, int nrows, int ncols>
    Matrix<T, ncols, nrows> transpose(const Matrix<T, nrows, ncols>& input);

    // specialised for square matrix
    template <typename T, int size>
    Matrix<T, size, size> transpose(const Matrix<T, size, size>& input);

}  
