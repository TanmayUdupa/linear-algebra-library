#include "../include/Matrix.hpp"

int main()
{
    double arr[2][3] = {{1, 2.2, 3}, {4, 5.1, 6.9}};
    Matrix<double, 2, 3> m(arr);
    m.print_matrix();

    cout << m[1][0] << endl;
    m[1][0] = 69;
    cout << m[1][0] << endl;

    return 0;
}