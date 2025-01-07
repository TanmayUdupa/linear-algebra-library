#include "Matrix.hpp"
#include<iostream>
using namespace std;
#include <type_traits>

//Made use of type trait for float type -  4 digit precision will come for any float type test case, this is not applicable
// for other data types

// Custom implementation of pow function for integer powers to avoid import of cmath library
template <typename T>
T custom_pow(T base, int exponent) {
    if (exponent < 0) {
        return static_cast<T>(1) / custom_pow(base, -exponent);
    } else if (exponent == 0) {
        return static_cast<T>(1);
    } else {
        T result = static_cast<T>(1);
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
        return result;
    }
}


template<typename T>
struct MatrixTraits {
    static constexpr bool is_floating_point = std::is_floating_point_v<T>;
    static constexpr int precision = 2; 
};


template<typename T, int nrows, int ncols>
class MatrixQR {
private:
    Matrix<T, nrows, ncols> Q;
    Matrix<T, ncols, ncols> R;

    T custom_sqrt(T value) {
        T epsilon = static_cast<T>(0.0001); 
        T guess = value / static_cast<T>(2);
        T diff = guess * guess - value;

        while (diff > epsilon || diff < -epsilon) {
            guess = (guess + value / guess) / static_cast<T>(2);
            diff = guess * guess - value;
        }
        return guess;
    }

  public:
    template <typename U>
    void lambda_sqrt(U value) {
        auto sqrt_func = [this](U val) { return custom_sqrt(val); };
        U result = sqrt_func(value);
        std::cout << "Square root of " << value << " is " << result << std::endl;
    }


public:
    MatrixQR(const Matrix<T, nrows, ncols>& A) {
        Q = Matrix<T, nrows, ncols>();
        R = Matrix<T, ncols, ncols>();

        Matrix<T, nrows, ncols> A_copy = A;  // Make a copy of A to avoid modifying original matrix

        for (int k = 0; k < ncols; ++k) {
            T norm = 0;
            for (int i = k; i < nrows; ++i) {
                norm += A_copy[i][k] * A_copy[i][k];
            }
           if constexpr (MatrixTraits<T>::is_floating_point) {
                // Use specialized behavior for floating-point types
                norm = std::abs(norm);
                if constexpr (MatrixTraits<T>::precision) {
                T epsilon = custom_pow(T(10), -MatrixTraits<T>::precision);
                    if (norm < epsilon) norm = T(0);
                }
} else {
    norm = custom_sqrt(norm);  // Use custom_sqrt function for non-floating-point types
}

            
            R[k][k] = norm;

            for (int i = k; i < nrows; ++i) {
                Q[i][k] = A_copy[i][k] / norm;
            }

            for (int j = k + 1; j < ncols; ++j) {
                T dot_product = 0;
                for (int i = k; i < nrows; ++i) {
                    dot_product += A_copy[i][j] * Q[i][k];
                }
                R[k][j] = dot_product;

                for (int i = k; i < nrows; ++i) {
                    A_copy[i][j] -= dot_product * Q[i][k];
                }
            }
        }
    }

    Matrix<T, nrows, ncols> getQ() const {
        return Q;
    }

    Matrix<T, ncols, ncols> getR() const {
        return R;
    }
};
