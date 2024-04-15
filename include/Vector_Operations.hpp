#pragma once
#include "Vector.hpp"

// Base case for variadic template vector addition
template <typename T, int nrows>
Vector<T, nrows> vector_add(const Vector<T, nrows>& vec) {
    return vec;
}

// Recursive case for variadic template vector addition
template <typename T, int nrows, typename... Rest>
Vector<T, nrows> vector_add(const Vector<T, nrows>& vec1, const Vector<T, nrows>& vec2, const Rest&... rest) {
    // Perform element-wise addition for the first two vectors
    Vector<T, nrows> result;
    for (int i = 0; i < nrows; ++i) {
        result[i] = vec1[i] + vec2[i];
    }
    // Recursively add the remaining vectors
    return vector_add(result, rest...);
}


// Vector subtraction
template <typename T, int nrows>
Matrix<T, nrows, 1> vector_subtract(const Matrix<T, nrows, 1>& vec1, const Matrix<T, nrows, 1>& vec2) {
    Matrix<T, nrows, 1> result;

    for (int i = 0; i < nrows; ++i) {
        result[i] = vec1[i] - vec2[i];
    }

    return result;
}

template <typename U, int nrows2>
U dot_product(const Vector<U, nrows2>& vec1, const Vector<U, nrows2>& vec2) {
    U result = 0;
    for (int i = 0; i < nrows2; ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}