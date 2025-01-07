#pragma once
#include "Vector.hpp"

//Vector addition and subtraction utilizes variadic template 

// Base case for vector addition
template <typename T, int nrows>
Vector<T, nrows> vector_add(const Vector<T, nrows>& vec) {
    return vec;
}

// Recursive case 
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

// Base case for vector subtraction
template <typename T, int nrows>
Vector<T, nrows> vector_subtract(const Vector<T, nrows>& vec) {
    return vec;
}

// Recursive case 
template <typename T, int nrows, typename... Rest>
Vector<T, nrows> vector_subtract(const Vector<T, nrows>& vec1, const Vector<T, nrows>& vec2, const Rest&... rest) {
    // Perform element-wise subtraction for the first two vectors
    Vector<T, nrows> result;
    for (int i = 0; i < nrows; ++i) {
        result[i] = vec1[i] - vec2[i];
    }
    // Recursively subtract the remaining vectors
    return vector_subtract(result, rest...);
}

template <typename U, int nrows2>
U dot_product(const Vector<U, nrows2>& vec1, const Vector<U, nrows2>& vec2) {
    U result = 0;
    for (int i = 0; i < nrows2; ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}