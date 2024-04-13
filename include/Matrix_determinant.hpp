#pragma once
#include "Matrix.hpp"  // Include your Matrix class definition
#include "Matrix_common.hpp"

namespace MatrixOperations {

    // Helper function to calculate determinant for a 2x2 matrix
    template <typename T>
    T determinant2x2(const Matrix<T, 2, 2>& mat);

    // Base case for determinant calculation (1x1 matrix)

    template <typename T>
    T determinant(const Matrix<T, 1, 1>& mat);

    // Forward declaration for determinant template
    template <typename T, int N>
    T determinant(const Matrix<T, N, N>& mat);

    template <typename T, int N>
    T determinant(const Matrix<T, N, N>& mat);

    template <typename T, int N, int... M>
    T determinant(const Matrix<T, N, M...>& mat);

    // Define a type trait to check if the matrix is square (optional)
    // template <typename MatrixType>
    // struct IsSquareMatrix {
    //     static constexpr bool value = MatrixType::get_nrows() == MatrixType::get_ncols();
    // };

    // Define lambda templates for custom transformations (optional)
    // auto customTransform = [](const auto& element) {
    //     // Implement custom transformation logic here
    //     return element;  // Example: identity transformation
    // };

    // Forward declaration for friend_determinant function
    template <typename T, int nrows, int ncols>
    T friend_determinant(const Matrix<T, nrows, ncols>& mat);

    // template double MatrixOperations::determinant(const Matrix<double, 3, 3>& mat);

}  // End of namespace MatrixOperations

