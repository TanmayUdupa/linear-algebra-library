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
            cout << matrix[i] << " ";
        }
        cout << endl;
    }

    // Other member functions specific to 1D Matrix
};

template<typename T, int nrows>
using Vector = Matrix<T, nrows, 1>;