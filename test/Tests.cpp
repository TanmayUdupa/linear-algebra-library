#include <iostream>
#include "../include/Matrix.hpp"
#include "../include/Vector.hpp"
#include "../include/Operations.hpp"
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

void test_matrix_addition() {
    double arr[2][2] = {{1, 2.2}, {4, 5.1}};
    Matrix<double, 2, 2> mat1(arr);
    double arr1[2][2] = {{1.0, 2.0}, {2.0, 1.0}};
    Matrix<double, 2, 2> mat2(arr1);
    double arr2[2][2] = {{1.0, 2.0}, {2.0, 1.0}};
    Matrix<double, 2, 2> mat3(arr2);
    // Matrix<int, 2, 2> mat1 = { {1, 2}, {3, 4} };
    // Matrix<int, 2, 2> mat2 = { {5, 6}, {7, 8} };
    // Matrix<int, 2, 2> mat3 = { {9, 10}, {11, 12} };

    // Test adding two matrices
    auto result1 = matrix_add(mat1, mat2);
    cout << "Matrix addition of mat1 and mat2:" << endl;
    result1.print_matrix();
    
    // Test adding three matrices
    auto result2 = matrix_add(mat1, mat2, mat3);
    cout << "Matrix addition of mat1, mat2, and mat3:" << endl;
    result2.print_matrix();
    
    // Test adding four matrices
    auto result3 = matrix_add(mat1, mat2, mat3, result1);
    cout << "Matrix addition of mat1, mat2, mat3, and result1:" << endl;
    result3.print_matrix();

    // Additional test case with integers
    int arr3[2][2] = { {1, 2}, {3, 4} };
    Matrix<int, 2, 2> intMat1(arr3);
    int arr4[2][2] = { {5, 6}, {7, 8} };
    Matrix<int, 2, 2> intMat2(arr4);
    int arr5[2][2] = { {9, 10}, {11, 12} };
    Matrix<int, 2, 2> intMat3(arr5);

    // Test adding two integer matrices
    auto intResult1 = matrix_add(intMat1, intMat2);
    cout << "Matrix addition of intMat1 and intMat2:" << endl;
    intResult1.print_matrix();
    
    // Test adding three integer matrices
    auto intResult2 = matrix_add(intMat1, intMat2, intMat3);
    cout << "Matrix addition of intMat1, intMat2, and intMat3:" << endl;
    intResult2.print_matrix();
    
    // Test adding four integer matrices
    auto intResult3 = matrix_add(intMat1, intMat2, intMat3, intResult1);
    cout << "Matrix addition of intMat1, intMat2, intMat3, and intResult1:" << endl;
    intResult3.print_matrix();
}

void test_matrix_subtraction() {
    // Example matrices
    double arr1[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix<double, 2, 2> mat1(arr1);

    double arr2[2][2] = {{0.5, 1.5}, {2.5, 3.5}};
    Matrix<double, 2, 2> mat2(arr2);

    // Subtract mat2 from mat1
    auto result = matrix_subtract(mat1, mat2);

    // Print the result
    cout << "Matrix subtraction result:" << endl;
    result.print_matrix();

     // Additional test case with integers
    int arr3[2][2] = { {1, 2}, {3, 4} };
    Matrix<int, 2, 2> intMat1(arr3);
    int arr4[2][2] = { {5, 6}, {7, 8} };
    Matrix<int, 2, 2> intMat2(arr4);

    // Test matrix subtraction with integers
    auto intResult_subtract = matrix_subtract(intMat1, intMat2);
    cout << "Matrix subtraction of intMat1 and intMat2:" << endl;
    intResult_subtract.print_matrix();
}


int main()
{
    cout << "Test Case 1: Creating matrix and accessing, editing elements" << endl;
    test_creation_matrix();

    cout << "Test Case 2: Creating vector and accessing, editing elements" << endl;
    test_creation_vector();

    cout << "Test Case 3: Matrix addition" << endl;
    test_matrix_addition();

    cout << "Test Case 4: Matrix subtraction" << endl;
    test_matrix_subtraction();

    cout << "All test cases passed\n" << endl;

    return 0;
}