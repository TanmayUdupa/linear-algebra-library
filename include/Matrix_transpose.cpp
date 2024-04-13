#include "Matrix_transpose.hpp"

namespace MatrixOperations {

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

    template <typename T, int nrows, int ncols>
    Matrix<T, ncols, nrows> friend_transpose(const Matrix<T, nrows, ncols>& input) {
        return transpose(input);
    }

}  // End of namespace MatrixOperations
