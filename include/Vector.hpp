#pragma once
#include "Matrix.hpp"


// Class Template specialization for 1D Matrix (Vector)
template <typename T, int nrows>
class Matrix<T, nrows, 1> {
static_assert(std::is_arithmetic_v<T>, "Vector elements must be of arithmetic type");
private:
    T* matrix;

public:

    // Default constructor - Initializes elements of vector to zero
    Matrix()
    {
        matrix = new T[nrows];
        for (int i = 0; i < nrows; i++)
        {
            matrix[i] = 0;
        }
    }

    // Parametrized constructor - To initialize elements of this vector with a 1D array passed as parameter
    Matrix(T matrix2[nrows])
    {
        matrix = new T[nrows];
        for (int i = 0; i < nrows; i++) 
        {                                 
            matrix[i] = matrix2[i];
        }
    }

    // Destructor to delete memory that was allocated
    ~Matrix()
    {
        delete[] matrix;
    }

    // Returns number of elements of vector
    int get_elements() const
    {
        return nrows;
    };

    // overridden operator for accessing index - const
    const T& operator[](int index) const {
        if (index < 0 || index >= nrows) {
            throw std::out_of_range("Index out of range");
        }
        return matrix[index];
    }

    // overridden operator for accessing index - non const
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

    // Function to print all elements of the vector
    void print_vector()
    {
        for (int i = 0; i < nrows; i++)
        {
            cout << matrix[i] << endl;
        }
        cout << endl;
    }

    // Function to slice the vector
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

    // Friend function that calculates dot product of two vectors
    template <typename U, int nrows2, int ncols2>
    friend T dot_product(const Matrix<U, nrows2, 1>& vec1, const Matrix<U, nrows2, 1>& vec2);

};

// Alias template to provide a convenient name for 1D Matrix specialization 
template<typename T, int nrows>
using Vector = Matrix<T, nrows, 1>;