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
    ~Matrix()
    {
        delete[] matrix;
    }

    int get_elements() const
    {
        return nrows;
    };

    T& operator[](int index)
    {
        return matrix[index];
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

    // Other member functions specific to 1D Matrix
};

template<typename T, int nrows>
using Vector = Matrix<T, nrows, 1>;