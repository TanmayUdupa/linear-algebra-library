#include <iostream>
#include "../include/Matrix.hpp"
#include "../include/Vector.hpp"
using namespace std;

void test_creation_matrix()
{
    Matrix<int, 4, 2> mat;
    cout << "Matrix created without passing an array, results in matrix of zeroes:" << endl;
    mat.print_matrix();
    cout << "Number of rows of matrix: " << mat.get_nrows();
    cout << "Number of columns of matrix: " << mat.get_ncols();
    
    double arr[2][3] = {{1, 2.2, 3}, {4, 5.1, 6.9}};
    Matrix<double, 2, 3> m(arr);
    cout << "Matrix created after passing an array:" << endl;
    m.print_matrix();

    cout << "Before editing value of element at (1, 0): " << m[1][0] << endl;
    m[1][0] = 69;
    cout << "After editing value of element at (1, 0): " <<  m[1][0] << endl;
    cout << endl;
}

void test_creation_vector()
{
    Vector<float, 4> vec;
    cout << "Vector created without passing an array, results in matrix of zeroes:" << endl;
    vec.print_vector();
    cout << "Number of elements: " << vec.get_elements() << endl;
    
    int arr2[3] = {1, 2, 3};
    Vector<int, 3> v(arr2);
    cout << "Vector created after passing an array:" << endl;
    v.print_vector();

    cout << "Before editing value of element at position 1: " << v[1] << endl;
    v[1] = 8;
    cout << "After editing value of element at position 1: " << v[1] << endl;
    cout << endl;
}

int main()
{
    cout << "Test Case 1: Creating matrix and accessing, editing elements" << endl;
    test_creation_matrix();

    cout << "Test Case 2: Creating vector and accessing, editing elements" << endl;
    test_creation_vector();

    cout << "All test cases passed\n" << endl;

    return 0;
}