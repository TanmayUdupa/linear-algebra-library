#pragma once
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

    const T* operator[](int index) const {
        return matrix[index];
    }


    T* operator[](int index)
    {
        return matrix[index];
    }

    void print_matrix()
    {
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Other member functions
};