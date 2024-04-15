#pragma once
#include<iostream>
#include <stdexcept>
#include <type_traits>
#include <iomanip>
using namespace std;

template <typename T, int nrows, int ncols>
concept is_square_matrix = nrows == ncols;


template <typename T, int nrows, int ncols>
class Matrix {
private:    
    T** matrix;

    template <typename U, int rows, int cols>
    struct Helper {
        friend Matrix<U, rows, cols> inverse(const Matrix<U, rows, cols>& mat);
        friend Matrix<U, rows, cols> adjoint(const Matrix<U, rows, cols>& mat);
    };

public:


    Matrix() 
    {
        matrix = new T*[nrows];
        for (int i = 0; i < nrows; i++) 
        {
            matrix[i] = new T[ncols];
        }
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                matrix[i][j] = 0;
            }
        }
    };
    Matrix(T matrix2[nrows][ncols])
    {
        matrix = new T*[nrows];
        for (int i = 0; i < nrows; i++) 
        {
            matrix[i] = new T[ncols];
        }
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                matrix[i][j] = matrix2[i][j];
            }
        }
    }

    Matrix(const Matrix& other) {
        matrix = new T*[nrows];
        for (int i = 0; i < nrows; i++) {
            matrix[i] = new T[ncols];
            for (int j = 0; j < ncols; j++) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }

// overridden operator for accessing index - const
const T* operator[](int index) const {
    return matrix[index];
}

// overridden operator for accessing index - non const
T* operator[](int index) {
    return matrix[index];
}

    Matrix(T value) {
        matrix = new T*[nrows];
        for (int i = 0; i < nrows; i++) {
            matrix[i] = new T[ncols];
            for (int j = 0; j < ncols; j++) {
                matrix[i][j] = value;  // Initialize all elements with the given value
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < nrows; i++) 
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    };

    int get_nrows() const
    {
        return nrows;
    };
    int get_ncols() const
    {
        return ncols;
    };

      // Copy assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            // Deallocate current memory
            // Allocate new memory and copy data
        }
        return *this;
    }

    // Move constructor (C++11 and above)
    Matrix(Matrix&& other) noexcept {
        // Move data from other to this
    }

    // Move assignment operator (C++11 and above)
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            // Move data from other to this
            // Reset other
        }
        return *this;
    }


void print_matrix() const {
    if constexpr (nrows == 1 && ncols == 1) {
        // Special handling for 1x1 matrices
        std::cout << matrix[0][0];
    } else {
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                if constexpr (std::is_same_v<T, float>) {
                    // Custom precision handling for float numbers
                    float value = matrix[i][j];
                    int integerPart = static_cast<int>(value);
                    float decimalPart = value - integerPart;
                    int precision = 4; // Specify the desired precision

                    // Print the integer part
                    std::cout << integerPart << ".";

                    // Print the decimal part with custom precision
                    for (int k = 0; k < precision; ++k) {
                        decimalPart *= 10;
                        int digit = static_cast<int>(decimalPart);
                        std::cout << digit;
                        decimalPart -= digit;
                    }
                    std::cout << " ";
                } else {
                    // Print other types as they are
                    std::cout << matrix[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}


    template<int slice_rows, int slice_cols>
    Matrix<T, slice_rows, slice_cols> slice(int start_row, int end_row, int start_col, int end_col) 
    {
        if (start_row < 0 || end_row > nrows - 1 || start_col < 0 || end_col > ncols - 1 || start_row > end_row || start_col > end_col)
        {
            throw std::out_of_range("Slice indices are out of range");
        }
        Matrix<T, slice_rows, slice_cols> result;
        for (int i = start_row; i <= end_row; i++) 
        {
            for (int j = start_col; j <= end_col; j++) 
            {
                result[i - start_row][j - start_col] = matrix[i][j];
            }
        }
        return result;
    } 

    template<int slice_rows>
    Matrix<T, slice_rows, 1> slice_vec(int start_row, int end_row, int col_no) 
    {
        if (start_row < 0 || end_row > nrows - 1 || start_row > end_row || col_no > ncols - 1)
        {
            throw std::out_of_range("Slice indices are out of range");
        }
        Matrix<T, slice_rows, 1> result;
        for (int i = start_row; i <= end_row; i++) 
        {
            result[i - start_row] = matrix[i][col_no];
        }
        return result;
    } 


template <int... Is, int... Js>
    Matrix<T, sizeof...(Is), sizeof...(Js)> normalize(std::integer_sequence<int, Is...>, std::integer_sequence<int, Js...>) {
        T min_val = *std::min_element(&matrix[0][0], &matrix[0][0] + nrows * ncols);
        T max_val = *std::max_element(&matrix[0][0], &matrix[0][0] + nrows * ncols);

        Matrix<T, sizeof...(Is), sizeof...(Js)> normalized;
        (((normalized[Is][Js] = (matrix[Is][Js] - min_val) / (max_val - min_val))), ...);

        // Print the normalized matrix
        std::cout << "Normalized matrix:" << std::endl;
        normalized.print_matrix();

        return normalized;
    }

    Matrix<T, nrows, ncols> normalize() {
        return normalize(std::make_integer_sequence<int, nrows>{}, std::make_integer_sequence<int, ncols>{});
    }


       void lu_decomposition(Matrix<T, nrows, ncols>& L, Matrix<T, nrows, ncols>& U) {
        L = Matrix<T, nrows, ncols>(); // Lower triangular matrix
        U = Matrix<T, nrows, ncols>(); // Upper triangular matrix

        check_square_matrix(*this);

        // Initialize L as identity matrix and U as a copy of this matrix
        for (int i = 0; i < nrows; ++i) {
            for (int j = 0; j < ncols; ++j) {
                if (i == j)
                    L[i][j] = 1;
                U[i][j] = matrix[i][j];
            }
        }

        for (int k = 0; k < nrows - 1; ++k) {
            for (int i = k + 1; i < nrows; ++i) {
                if (U[k][k] == 0) {
                    throw invalid_argument("LU decomposition failed: Zero pivot encountered");
                }
                T factor = U[i][k] / U[k][k];
                L[i][k] = factor;
                for (int j = k; j < ncols; ++j) {
                    U[i][j] -= factor * U[k][j];
                }
            }
        }
        }
    
};

// Function to calculate the inverse of a square matrix
template <typename T, int nrows, int ncols>
Matrix<T, nrows, ncols> inverse(const Matrix<T, nrows, ncols>& mat) {
    static_assert(nrows == ncols, "Inverse can only be calculated for square matrices");
    Matrix<T, nrows, ncols> inverted;
    // Implement inverse logic manually
    return inverted;
}

// Function to calculate the adjoint of a square matrix
template <typename T, int nrows, int ncols>
Matrix<T, nrows, ncols> adjoint(const Matrix<T, nrows, ncols>& mat) {
    static_assert(nrows == ncols, "Adjoint can only be calculated for square matrices");
    Matrix<T, nrows, ncols> adj;
    // Implement adjoint logic manually
    return adj;
}

template <typename T, int nrows, int ncols>
void check_square_matrix(const Matrix<T, nrows, ncols>& matrix) {
    static_assert(is_square_matrix<T, nrows, ncols>, "Matrix must be a square matrix");
}