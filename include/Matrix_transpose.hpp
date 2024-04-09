#pragma once
#include "Matrix.hpp"  // Include your Matrix class definition

// Define your transpose function in a namespace or a class, depending on your design preference
namespace MatrixOperations {

    // Define a generic transpose function using variadic templates
    template <typename T, int nrows, int ncols>
    Matrix<T, ncols, nrows> transpose(const Matrix<T, nrows, ncols>& input) {
        Matrix<T, ncols, nrows> result;

        // Implement the transpose logic here
        for (int i = 0; i < nrows; ++i) {
            for (int j = 0; j < ncols; ++j) {
                result[j][i] = input[i][j];
            }
        }

        return result;
    }

    // Specialize the transpose function for square matrices -  template specialisation used
    template <typename T, int size>
    Matrix<T, size, size> transpose(const Matrix<T, size, size>& input) {
        Matrix<T, size, size> result;

        // Implement specialized transpose logic for square matrices if needed
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result[j][i] = input[i][j];
            }
        }

        return result;
    }

    // Define lambda templates for custom transformations (optional)
    auto customTransform = [](const auto& element) {
        // Implement custom transformation logic here
        return element;  // Example: identity transformation
    };

    // Define a type trait to check if the matrix is square (optional)
    template <typename MatrixType>
    struct IsSquareMatrix {
        static constexpr bool value = MatrixType::get_nrows() == MatrixType::get_ncols();
    };

    // Define template friendship for privileged access (optional)
    template <typename T, int nrows, int ncols>
    class Matrix;  // Forward declaration

    template <typename T, int nrows, int ncols>
    Matrix<T, ncols, nrows> friend_transpose(const Matrix<T, nrows, ncols>& input) {
        return transpose(input);
    }

}  // End of namespace MatrixOperations
