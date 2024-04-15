#pragma once
#include "Matrix.hpp"


// Template specialization for 1D Matrix (Vector)
template <typename T, int nrows>
class Matrix<T, nrows, 1> {
private:
    T* matrix;

public:
    Matrix()
    {
        matrix = new T[nrows];
        for (int i = 0; i < nrows; i++)
        {
            matrix[i] = 0;
        }
    }
    Matrix(T matrix2[nrows])
    {
        matrix = new T[nrows];
        for (int i = 0; i < nrows; i++) 
        {                                 
            matrix[i] = matrix2[i];
        }
    }

// Vector(const T(&array)[nrows]) {
//         matrix = new T[nrows];
//         for (int i = 0; i < nrows; i++) {
//             matrix[i] = array[i];
//         }
//     }


    ~Matrix()
    {
        delete[] matrix;
    }

    int get_elements() const
    {
        return nrows;
    };

    const T& operator[](int index) const {
        if (index < 0 || index >= nrows) {
            throw std::out_of_range("Index out of range");
        }
        return matrix[index];
    }

    T& operator[](int index)
    {
        return matrix[index];
    }

       // Copy constructor
    Matrix(const Matrix& other) {
        matrix = new T[nrows];
        for (int i = 0; i < nrows; i++) {
            matrix[i] = other.matrix[i];
        }
    }

    // Copy assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            delete[] matrix; // Deallocate current memory
            matrix = new T[nrows]; // Allocate new memory
            for (int i = 0; i < nrows; i++) {
                matrix[i] = other.matrix[i]; // Copy data
            }
        }
        return *this;
    }

    // Move constructor (C++11 and above)
    Matrix(Matrix&& other) noexcept : matrix(nullptr) {
        std::swap(matrix, other.matrix); // Move data
    }

    // Move assignment operator (C++11 and above)
    Matrix& operator=(Matrix&& other) noexcept {
        if (this != &other) {
            delete[] matrix; // Deallocate current memory
            matrix = nullptr;
            std::swap(matrix, other.matrix); // Move data
        }
        return *this;
    }

    void print_vector()
    {
        for (int i = 0; i < nrows; i++)
        {
            cout << matrix[i] << endl;
        }
        cout << endl;
    }

    template<int slice_rows>
    Matrix<T, slice_rows, 1> slice_vec(int start_row, int end_row) 
    {
        if (start_row < 0 || end_row > nrows - 1 || start_row > end_row)
        {
            throw std::out_of_range("Slice indices are out of range");
        }
        Matrix<T, slice_rows, 1> result;
        for (int i = start_row; i <= end_row; i++) 
        {
            result[i - start_row] = matrix[i];
        }
        return result;
    } 

    template <typename U, int nrows2, int ncols2>
    friend T dot_product(const Matrix<U, nrows2, 1>& vec1, const Matrix<U, nrows2, 1>& vec2);

    // Other member functions specific to 1D Matrix
};

template<typename T, int nrows>
using Vector = Matrix<T, nrows, 1>;