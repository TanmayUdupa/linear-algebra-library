#pragma once
#include<iostream>
#include <iomanip>
using namespace std;


template <typename T, int nrows, int ncols>
class Matrix {
private:    
    T** matrix;

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

    // Const operator[] for read-only access
const T* operator[](int index) const {
    return matrix[index];
}

// Non-const operator[] for read and write access
T* operator[](int index) {
    return matrix[index];
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

    // const T* operator[](int index) const {
    //     return matrix[index];
    // }


    // T* operator[](int index)
    // {
    //     return matrix[index];
    // }

    // void print_matrix()
    // {
    //     for (int i = 0; i < nrows; i++)
    //     {
    //         for (int j = 0; j < ncols; j++)
    //         {
    //             cout << matrix[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

//     void print_matrix()
// {
//     for (int i = 0; i < nrows; i++)
//     {
//         for (int j = 0; j < ncols; j++)
//         {
//             if constexpr (std::is_floating_point_v<decltype(matrix[i][j])>) {
//                 // Custom precision handling for floating-point numbers
//                 float value = matrix[i][j];
//                 int integerPart = static_cast<int>(value);
//                 float decimalPart = value - integerPart;
//                 int precision = 4; // Specify the desired precision

//                 // Print the integer part
//                 std::cout << integerPart << ".";

//                 // Print the decimal part with custom precision
//                 for (int k = 0; k < precision; ++k) {
//                     decimalPart *= 10;
//                     int digit = static_cast<int>(decimalPart);
//                     std::cout << digit;
//                     decimalPart -= digit;
//                 }
//                 std::cout << " ";
//             } else {
//                 // Print other types as they are
//                 std::cout << matrix[i][j] << " ";
//             }
//         }
//         std::cout << std::endl;
//     }
// }

// void print_matrix() const
// {
//     for (int i = 0; i < nrows; i++)
//     {
//         for (int j = 0; j < ncols; j++)
//         {
//             if constexpr (std::is_floating_point_v<T>) {
//                 // Custom precision handling for floating-point numbers
//                 float value = static_cast<float>(matrix[i][j]);
//                 int integerPart = static_cast<int>(value);
//                 float decimalPart = value - integerPart;
//                 int precision = 4; // Specify the desired precision

//                 // Print the integer part
//                 std::cout << integerPart << ".";

//                 // Print the decimal part with custom precision
//                 for (int k = 0; k < precision; ++k) {
//                     decimalPart *= 10;
//                     int digit = static_cast<int>(decimalPart);
//                     std::cout << digit;
//                     decimalPart -= digit;
//                 }
//                 std::cout << " ";
//             } else {
//                 // Print other types as they are
//                 std::cout << matrix[i][j] << " ";
//             }
//         }
//         std::cout << std::endl;
//     }
// }

void print_matrix() const
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
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

    //  template<int concat_dim>
    // Matrix<T, nrows, ncols + concat_dim> concat(const Matrix<T, nrows, concat_dim>& other) {
    //     Matrix<T, nrows, ncols + concat_dim> result;
    //     for (int i = 0; i < nrows; ++i) {
    //         for (int j = 0; j < ncols; ++j) {
    //             result[i][j] = matrix[i][j];  // Copy elements from the first matrix
    //         }
    //         for (int j = 0; j < concat_dim; ++j) {
    //             result[i][ncols + j] = other[i][j];  // Concatenate elements from the second matrix
    //         }
    //     }
    //     return result;
    // }

    // Other member functions
};