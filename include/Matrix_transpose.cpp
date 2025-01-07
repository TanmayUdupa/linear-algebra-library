#include "Matrix_transpose.hpp"
// Template specialisation has been used

namespace MatrixOperations {

    template <typename T, int nrows, int ncols>
    Matrix<T, ncols, nrows> transpose(const Matrix<T, nrows, ncols>& input) {
        Matrix<T, ncols, nrows> result;

        // transpose logic
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

        // specialised for square matrix - template specialisation
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result[j][i] = input[i][j];
            }
        }

        return result;
    }
}  
