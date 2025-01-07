#include <iostream>
#include <cmath>
#include "../include/Matrix.hpp"
#include "../include/Vector.hpp"
#include "../include/Operations.hpp"
#include "../include/Vector_Operations.hpp"
#include "../include/Matrix_transpose.hpp"
#include "../include/Matrix_determinant.hpp"
#include "../include/Matrix_determinant.cpp"
#include "../include/Matrix_transpose.cpp"
#include "../include/MatrixQR.hpp"
using namespace std;


//This file include all test case functions for all the functionalities implemented

void test_creation_matrix()
{
    Matrix<int, 4, 2> mat;
    cout << "Matrix created without passing an array, results in matrix of zeroes:" << endl;
    mat.print_matrix();
    cout << "Number of rows of matrix: " << mat.get_nrows() << endl  ;
    cout << "Number of columns of matrix: " << mat.get_ncols();
    cout << endl << endl;

    double arr[2][3] = {{1, 2.2, 3}, {4, 5.1, 6.9}};
    Matrix<double, 2, 3> m(arr);
    cout << "Matrix created after passing an array:" << endl;
    m.print_matrix();
    cout << endl;

    cout << "Before editing value of element at (1, 0): " << m[1][0] << endl;
    m[1][0] = 69;
    cout << "After editing value of element at (1, 0): " <<  m[1][0] << endl;
    cout << endl;
    cout << "=================================================================================================================";
}

void test_creation_vector()
{
    Vector<float, 4> vec;
    cout << "Vector created without passing an array, results in matrix of zeroes:" << endl;
    vec.print_vector();
    cout << "Number of elements: " << vec.get_elements() << endl;
    cout << endl;
    
    int arr2[3] = {1, 2, 3};
    Vector<int, 3> v(arr2);
    cout << "Vector created after passing an array:" << endl;
    v.print_vector();

    cout << "Before editing value of element at position 1: " << v[1] << endl;
    v[1] = 8;
    cout << "After editing value of element at position 1: " << v[1] << endl;
    cout << endl;
    cout << "=================================================================================================================";
}

void test_matrix_addition() {
    //Variadic template has been used 
    double arr[2][2] = {{1, 2.2}, {4, 5.1}};
    Matrix<double, 2, 2> mat1(arr);
    double arr1[2][2] = {{1.0, 2.0}, {2.0, 1.0}};
    Matrix<double, 2, 2> mat2(arr1);
    double arr2[2][2] = {{1.0, 2.0}, {2.0, 1.0}};
    Matrix<double, 2, 2> mat3(arr2);

    // two matrices addition
    auto result1 = matrix_add(mat1, mat2);
    cout << "Matrix addition of mat1 and mat2:" << endl;
    result1.print_matrix();
    cout << endl;
    
    // three matrices addition
    auto result2 = matrix_add(mat1, mat2, mat3);
    cout << "Matrix addition of mat1, mat2, and mat3:" << endl;
    result2.print_matrix();
    cout << endl;
    
    // four matries addition
    auto result3 = matrix_add(mat1, mat2, mat3, result1);
    cout << "Matrix addition of mat1, mat2, mat3, and result1:" << endl;
    result3.print_matrix();
    cout << endl;

    // int
    int arr3[2][2] = { {1, 2}, {3, 4} };
    Matrix<int, 2, 2> intMat1(arr3);
    int arr4[2][2] = { {5, 6}, {7, 8} };
    Matrix<int, 2, 2> intMat2(arr4);
    int arr5[2][2] = { {9, 10}, {11, 12} };
    Matrix<int, 2, 2> intMat3(arr5);

    // two matrices addition
    auto intResult1 = matrix_add(intMat1, intMat2);
    cout << "Matrix addition of intMat1 and intMat2:" << endl;
    intResult1.print_matrix();
    cout << endl;
    
    // three matrices addition
    auto intResult2 = matrix_add(intMat1, intMat2, intMat3);
    cout << "Matrix addition of intMat1, intMat2, and intMat3:" << endl;
    intResult2.print_matrix();
    cout << endl;
    
    //four matrices addition
    auto intResult3 = matrix_add(intMat1, intMat2, intMat3, intResult1);
    cout << "Matrix addition of intMat1, intMat2, intMat3, and intResult1:" << endl;
    intResult3.print_matrix();
    cout << endl;
    cout << "=================================================================================================================";
}

void test_matrix_subtraction() {
    // int
    double arr1[2][2] = {{1.0, 2.0}, {3.0, 4.0}};
    Matrix<double, 2, 2> mat1(arr1);

    double arr2[2][2] = {{0.5, 1.5}, {2.5, 3.5}};
    Matrix<double, 2, 2> mat2(arr2);

    auto result = matrix_subtract(mat1, mat2);

    cout << "Matrix subtraction result:" << endl;
    result.print_matrix();
    cout << endl;

     // int test case
    int arr3[2][2] = { {1, 2}, {3, 4} };
    Matrix<int, 2, 2> intMat1(arr3);
    int arr4[2][2] = { {5, 6}, {7, 8} };
    Matrix<int, 2, 2> intMat2(arr4);

    auto intResult_subtract = matrix_subtract(intMat1, intMat2);
    cout << "Matrix subtraction of intMat1 and intMat2:" << endl;
    intResult_subtract.print_matrix();

    cout << endl;

    int arr5[2][2] = { {9, 10}, {11, 12} };
    Matrix<int, 2, 2> intMat3(arr5);

    auto intResult_subtract_multi = matrix_subtract(intMat1, intMat2, intMat3);
    cout << "Matrix subtraction of intMat1 by intMat2 and their difference by intMat3:" << endl;
    intResult_subtract_multi.print_matrix();

    cout << endl;
    cout << "=================================================================================================================";
}

void test_matrix_multiplication() {

    //double test case
    double arr1[2][3] = { {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0} };
    Matrix<double, 2, 3> mat1(arr1);

    double arr2[3][2] = { {7.0, 8.0}, {9.0, 10.0}, {11.0, 12.0} };
    Matrix<double, 3, 2> mat2(arr2);

    Matrix<double, 2, 2> result1 = matrix_multiply(mat1, mat2);

    cout << "Matrix multiplication result:" << endl;
    result1.print_matrix();
    cout << endl;

    // int test case
    int arr3[2][3] = { {1, 2, 3}, {4, 5, 6} };
    Matrix<int, 2, 3> mat3(arr3);

    int arr4[3][2] = { {7, 8}, {9, 10}, {11, 12} };
    Matrix<int, 3, 2> mat4(arr4);

    Matrix<int, 2, 2> result2 = matrix_multiply(mat3, mat4);

    cout << "Matrix multiplication result (int):" << endl;
    result2.print_matrix();
    cout << endl;
    cout << "=================================================================================================================";
}

void test_vector_addition() {
    //variadic template has been used for this functionality
    // int test case
    int arr[3] = {1, 2, 3};
    Vector<int, 3> vec1(arr); 
    int arr1[3] = {1, 2, 3};
    Vector<int, 3> vec2(arr1); 
    int arr2[3] = {1, 2, 3};
    Vector<int, 3> vec3(arr2); 

    //two matrices
    auto result1 = vector_add(vec1, vec2);
    cout << "Vector addition of vec1 and vec2:" << endl;
    result1.print_vector();
    
    // three matrices
    auto result2 = vector_add(vec1, vec2, vec3);
    cout << "Vector addition of vec1, vec2, and vec3:" << endl;
    result2.print_vector();

    double arr3[3] = {1.5, 2.5, 3.5};
    Vector<double, 3> vec4(arr3); 
    double arr4[3] = {0.5, 1.5, 2.5};
    Vector<double, 3> vec5(arr4); 
    double arr5[3] = {2.5, 3.5, 4.5};
    Vector<double, 3> vec6(arr5); 

    auto result3 = vector_add(vec4, vec5);
    cout << "Vector addition of vec4 and vec5:" << endl;
    result3.print_vector();
    
    auto result4 = vector_add(vec4, vec5, vec6);
    cout << "Vector addition of vec4, vec5, and vec6:" << endl;
    result4.print_vector();
    cout << "=================================================================================================================";
}

void test_vector_subtraction() {
    // int test case
    int arr1[3] = {1, 2, 3};
    Vector<int, 3> vec1(arr1); 
    int arr2[3] = {4, 5, 6};
    Vector<int, 3> vec2(arr2); 
   
    auto result = vector_subtract(vec1, vec2);
    cout << "Vector subtraction of vec1 and vec2:" << endl;
    result.print_vector();

    //double test case
    double arr3[3] = {3.5, 4.5, 5.5};
    Vector<double, 3> vec3(arr3); 
    double arr4[3] = {1.5, 2.5, 3.5};
    Vector<double, 3> vec4(arr4); 

    auto result1 = vector_subtract(vec3, vec4);
    cout << "Vector subtraction of vec3 and vec4:" << endl;
    result1.print_vector();

    double arr5[3] = {8.5, 9.5, 10.5};
    Vector<double, 3> vec5(arr5);

    auto result2 = vector_subtract(vec3, vec4, vec5);
    cout << "Vector subtraction of vec3 by vec4 and their difference by vec5:" << endl;
    result2.print_vector();
    cout << "=================================================================================================================";
}


void test_matrix_transpose() {
    // double -  rectangular matrix
    double arr[2][3] = {{1.5, 2.5, 3.5}, {4.5, 5.5, 6.5}};
    Matrix<double, 2, 3> mat(arr);

    auto transposed = MatrixOperations::transpose(mat);
    cout << "Original double matrix (rectangular)" << endl;
    mat.print_matrix();
    cout << "Transposed double matrix (rectangular)" << endl;
    transposed.print_matrix();
    cout << endl;

    // int -  rectangular matrix
    int arr2[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    Matrix<int, 3, 2> intMat(arr2);

    auto intTransposed = MatrixOperations::transpose(intMat);
    cout << "Original int matrix (rectangular)" << endl;
    intMat.print_matrix();
    cout << "Transposed int matrix (rectangular):" << endl;
    intTransposed.print_matrix();
    cout << endl;
    // float - square matrix
    float arr3[2][2] = {{1.1f, 2.2f}, {3.3f, 4.4f}};
    Matrix<float, 2, 2> squareMat(arr3);

    auto squareTransposed = MatrixOperations::transpose(squareMat);
    cout << "Original float matrix (square)" << endl;
    squareMat.print_matrix();
    cout << "Transposed square float matrix (square)" << endl;
    squareTransposed.print_matrix();
    cout << endl;
    cout << "=================================================================================================================";
}


void test_determinant() {
    // Rectangular matrix - double
    double arr1[2][3] = {{1.0, 2.5, 1.0}, {3.0, 4.0, 1.0}};
    Matrix<double, 2, 3> mat1(arr1);
    cout << "Original rectangular matrix (double):" << endl;
    mat1.print_matrix();
    double det1 = MatrixOperations::determinant(mat1);
    cout << "Determinant of the rectangular matrix (double): " << det1 << endl;
    cout << endl;

    // // 1x1 matrix - double
    // double arr2[1][1] = {{5.0}};
    // Matrix<double, 1, 1> mat2(arr2);
    // mat2.print_matrix();
    // double det2 = MatrixOperations::determinant(mat2);
    // cout << "Determinant of the 1x1 matrix (double): " << det2 << endl;

    // Square matrix - double
    double arr[3][3] = {{1.0, 7.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    Matrix<double, 3, 3> mat(arr);
    cout << "Original square matrix (double):" << endl;
    mat.print_matrix();
    double det = MatrixOperations::determinant(mat);
    cout << "Determinant of the square matrix (double): " << det << endl;
    cout << endl;

    // Square matrix - int
    int arr3[2][2] = {{2, 3}, {1, 4}};
    Matrix<int, 2, 2> mat3(arr3);
    cout << "Original square matrix (int):" << endl;
    mat3.print_matrix();
    int det3 = MatrixOperations::determinant(mat3);
    cout << "Determinant of the square matrix (int): " << det3 << endl << "\n";

    // Rectangular matrix - float
    float arr4[2][3] = {{1.5f, 2.7f, 3.2f}, {4.1f, 5.6f, 6.9f}};
    Matrix<float, 2, 3> mat4(arr4);
    cout << "Original rectangular matrix (float):" << endl;
    mat4.print_matrix();
    float det4 = MatrixOperations::determinant(mat4);
    cout << "Determinant of the rectangular matrix (float): " << det4 << endl << "\n";
    cout << "=================================================================================================================";
}


void test_qr_decomposition() {
    //double square matrix
    double arr[3][3] = { {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
    Matrix<double, 3, 3> mat(arr);
    cout << "Original double square matrix for QR decomposition:" << endl;
    mat.print_matrix();
    cout << endl;

    // QR decomposition
    MatrixQR<double, 3, 3> qr(mat);
    Matrix<double, 3, 3> Q = qr.getQ();
    Matrix<double, 3, 3> R = qr.getR();

    cout << "Orthogonal Q matrix:" << endl;
    Q.print_matrix();
    cout << endl;
    cout << "Upper triangular R matrix:" << endl;
    R.print_matrix();
    cout << endl;

    // double rectangular matrix
    double arr2[3][2] = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0} };
    Matrix<double, 3, 2> mat2(arr2);
    cout << "Original double rectangular matrix for QR decomposition:" << endl;
    mat2.print_matrix();
    cout << endl;

    MatrixQR<double, 3, 2> qr2(mat2);
    Matrix<double, 3, 2> Q2 = qr2.getQ();
    Matrix<double, 2, 2> R2 = qr2.getR();  // R is 2x2 for a 3x2 matrix

    cout << "Orthogonal Q matrix (rectangular):" << endl;
    Q2.print_matrix();
    cout << endl;
    cout << "Upper triangular R matrix (rectangular):" << endl;
    R2.print_matrix();
    cout << endl;

    //float square matrix
    float arr3[3][3] = {{1.0f, 2.45537895693847f, 3.0f}, {4.0f, 5.78654654654f, 6.0f}, {7.0f, 8.0f, 9.0f}};
    Matrix<float, 3, 3> mat3(arr3);
    cout << "Original float square matrix for QR decomposition:" << endl;
    mat3.print_matrix();
    cout << endl;

    MatrixQR<float, 3, 3> qr3(mat3);
    qr.lambda_sqrt(25.78);
    Matrix<float, 3, 3> Q3 = qr3.getQ();
    Matrix<float, 3, 3> R3 = qr3.getR();

    cout << "Orthogonal Q matrix (float):" << endl;
    Q3.print_matrix();
    cout << endl;

    cout << "Upper triangular R matrix (float):" << endl;
    R3.print_matrix();
    cout << endl;
    cout << "=================================================================================================================";
}

void test_lu_decomposition()
{
    Matrix<int, 3, 3> L;
    Matrix<int, 3, 3> U;
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int, 3, 3> mat(arr);
    mat.lu_decomposition(L, U);
    cout << "L matrix:" << endl;
    L.print_matrix();
    cout << endl;
    cout << "U matrix:" << endl;
    U.print_matrix();
    cout << "=================================================================================================================";
}  

void test_element_wise()
{
    double arr[3][3] = { { 1.0, 2.0, 3.0 }, { 4.0, 5.0, 6.0 }, { 7.0, 8.0, 9.0 } };
    Matrix<double, 3, 3> matrix(arr);
    cout << "Matrix to be tested:" << endl;
    matrix.print_matrix();
    cout << endl;

    // Apply the square root function to each element
    Matrix<double, 3, 3> sqrt_matrix = apply_elementwise(matrix, [](double x) { return sqrt(x); });
    cout << "Applying square root to each element:" << endl;
    sqrt_matrix.print_matrix();
    cout << endl;

    // Apply a custom lambda function to each element
    Matrix<double, 3, 3> custom_matrix = apply_elementwise(matrix, [](double x) { return x * x + 2.0 * x; });
    cout << "Applying custom lambda function to each element:" << endl;
    custom_matrix.print_matrix();
    cout << endl;   

    int arr2[3] = {1, 2, 3};
    Vector<int, 3> v(arr2);
    cout << "Vector to be tested:" << endl;
    v.print_vector();

    auto custom_vector= apply_elementwise(v, [](double x) { return x * x + 2.0 * x; });
    cout << "Applying custom lambda function to each element:" << endl;
    custom_vector.print_vector();  

    cout << "=================================================================================================================";
}

void test_matrix_normalization() {
    // only works for square matrices
    // double
    double arr[3][3] = { {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
    Matrix<double, 3, 3> mat(arr);
    cout << "Original matrix for normalization:" << endl;
    mat.print_matrix();
    cout << endl;
    mat.normalize();
    cout << endl;
    

    //int
    int arr2[2][2] = { {3, 6}, {9, 12} };
    Matrix<int, 2, 2> mat2(arr2);
    cout << "Original integer matrix for normalization:" << endl;
    mat2.print_matrix();
    cout << endl;
    mat2.normalize();
    cout << endl << endl;
    


    //float
    float arr3[3][3] = { {100.7f, 18.5f, 5.5f}, {123.8f, 0.75f, 56.5f}, {7.5f, 8.5f, 9.5f} };
    Matrix<float, 3, 3> mat3(arr3);
    cout << "Original float matrix for normalization:" << endl;
    mat3.print_matrix();
    cout << endl;
    mat3.normalize();
    cout << endl;
    cout << "=================================================================================================================";
}

void test_matrix_inverse() {
    // Define a square matrix for testing
    double arr[3][3] = { {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
    Matrix<double, 3, 3> mat(arr);
    cout << "Original matrix for inverse calculation:" << endl;
    mat.print_matrix();
    Matrix<double, 3, 3> inversedMat = inverse(mat);
    cout << "Inverse matrix:" << endl;
    inversedMat.print_matrix();
    cout << "=================================================================================================================";
}

void test_matrix_adjoint() {
    // Define a square matrix for testing
    double arr[3][3] = { {1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0} };
    Matrix<double, 3, 3> mat(arr);
    cout << "Original matrix for adjoint calculation:" << endl;
    mat.print_matrix();

    // Calculate the adjoint of the matrix
    Matrix<double,3,3> adjointMat = adjoint(mat);
    cout << "Adjoint matrix:" << endl;
    adjointMat.print_matrix();
    cout << "=================================================================================================================";
}

void test_vector_dot_product()
{
    int arr[3] = {1, 2, 3};
    Vector<int, 3> vec1(arr); 
    cout << "Original integer vector 1: " << endl;
    vec1.print_vector();
    cout << endl;
    int arr1[3] = {1, 2, 3};
    Vector<int, 3> vec2(arr1); 
    cout << "Original integer vector 2: " << endl;
    vec2.print_vector();
    cout << endl;
    cout << "Dot product of vectors: " << dot_product(vec1, vec2) << endl;
    cout << "=================================================================================================================";
}


int main()
{
    cout << "Test Case 1: Creating matrix and accessing, editing elements" << endl << "\n";
    test_creation_matrix();
    cout << endl;

    cout << "Test Case 2: Creating vector and accessing, editing elements" << endl << "\n";
    test_creation_vector();
    cout << endl;

    cout << "Test Case 3: Matrix addition" << endl << "\n";
    test_matrix_addition();
    cout << endl;

    cout << "Test Case 4: Matrix subtraction" << endl << "\n";
    test_matrix_subtraction();
    cout << endl;

    cout << "Test Case 5: Matrix multiplication" << endl << "\n";
    test_matrix_multiplication();
    cout << endl;

    cout << "Test Case 6: Vector addition" << endl << "\n";
    test_vector_addition();
    cout << endl;

    cout << "Test Case 7: Vector subtraction" << endl << "\n";
    test_vector_subtraction();
    cout << endl;

    cout << "Test Case 8: Matrix Transpose" << endl << "\n";
    test_matrix_transpose();
    cout << endl;

    cout << "Test Case 9: Determining the determinant of a matrix" << endl << "\n";
    test_determinant();
    cout << endl;

    cout << "Test Case 10: Determining the QR decomposition of a matrix" << endl << "\n";
    test_qr_decomposition();
    cout << endl;
   
    cout << "Test Case 11: Determining the LU decomposition of a matrix" << endl << "\n";
    test_lu_decomposition();
    cout << endl;

    cout << "Test Case 12: Applying elementwise operations to matrix / vector" << endl << "\n";
    test_element_wise();
    cout << endl;

    cout << "Test Case 13: Normalised matrices using fold expression" << endl << "\n";
    test_matrix_normalization();
    cout << endl;

    cout << "Test Case 14: Inverse of matrix with template friendship" << endl << "\n";
    test_matrix_inverse();
    cout << endl;

    cout << "Test Case 15: Adjoint of matrix with template friendship" << endl << "\n";
    test_matrix_adjoint();
    cout << endl;

    cout << "Test Case 16: Dot product of vector" << endl << "\n";
    test_vector_dot_product();
    cout << endl;

    cout << "All test cases passed\n" << endl;

    return 0;
}