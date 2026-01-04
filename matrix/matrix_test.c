//
// Created by mac on 11.12.2025.
//

#include "matrix.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define EPS 1e-9

static bool double_eq(double a, double b) {
    return fabs(a - b) < EPS;
}

void test_basic_creation(void) {
    Matrix m0 = create_empty();
    assert(!is_valid(&m0));

    Matrix v = create_vector(3);
    assert(is_valid(&v));
    assert(v.rows == 1 && v.cols == 3);
    assert(double_eq(get_element(&v, 0, 1), 0.0));

    Matrix z = create_zero(2, 2);
    assert(double_eq(get_element(&z, 1, 1), 0.0));

    Matrix c = create_const(2, 3, 5.5);
    assert(double_eq(get_element(&c, 0, 2), 5.5));

    destroy(&m0);
    destroy(&v);
    destroy(&z);
    destroy(&c);
}

void test_identity(void) {
    Matrix I = create_identity(2, 2);
    assert(double_eq(get_element(&I, 0, 0), 1.0));
    assert(double_eq(get_element(&I, 0, 1), 0.0));
    assert(double_eq(get_element(&I, 1, 1), 1.0));

    Matrix m = create_const(2, 2, 99.0);
    set_identity(&m);
    assert(double_eq(get_element(&m, 1, 0), 0.0));
    assert(double_eq(get_element(&m, 1, 1), 1.0));

    destroy(&I);
    destroy(&m);
}

void test_arithmetic(void) {
    Matrix A = create_const(2, 2, 4.0);
    Matrix B = create_const(2, 2, 1.0);

    Matrix sum = add(&A, &B);
    assert(double_eq(get_element(&sum, 0, 0), 5.0));

    Matrix diff = subtract(&A, &B);
    assert(double_eq(get_element(&diff, 0, 0), 3.0));

    Matrix scaled = multiply_scalar(&A, 0.5);
    assert(double_eq(get_element(&scaled, 0, 0), 2.0));

    destroy(&A); destroy(&B);
    destroy(&sum); destroy(&diff); destroy(&scaled);
}

void test_multiply(void) {
    Matrix A = create(1, 2);
    set_element(&A, 0, 0, 1); set_element(&A, 0, 1, 2);

    Matrix B = create(2, 1);
    set_element(&B, 0, 0, 3); set_element(&B, 1, 0, 4);

    Matrix C = multiply(&A, &B);

    destroy(&A);
    destroy(&B);
    destroy(&C);
}

void test_transpose(void) {
    Matrix A = create(2, 3);
    set_element(&A, 0, 0, 1); set_element(&A, 0, 1, 2); set_element(&A, 0, 2, 3);
    set_element(&A, 1, 0, 4); set_element(&A, 1, 1, 5); set_element(&A, 1, 2, 6);

    Matrix At = transpose(&A);
    assert(At.rows == 3 && At.cols == 2);
    assert(double_eq(get_element(&At, 2, 1), 6.0)); // At[2][1] = A[1][2] = 6

    destroy(&A);
    destroy(&At);
}

void test_determinant(void) {
    Matrix m = create(2, 2);
    set_element(&m, 0, 0, 2); set_element(&m, 0, 1, 1);
    set_element(&m, 1, 0, 1); set_element(&m, 1, 1, 2);
    double det = determinant(&m);
    assert(double_eq(det, 3.0));
    destroy(&m);
}

void test_resize(void) {
    Matrix m = create_const(2, 2, 1.0);
    Matrix resized = resize(&m, 3, 3);
    assert(resized.rows == 3 && resized.cols == 3);
    assert(double_eq(get_element(&resized, 0, 0), 1.0));
    destroy(&m);
    destroy(&resized);
}

void test_inverse(void) {
    Matrix m = create_identity(2, 2);
    Matrix inv = inverse(&m);
    assert(double_eq(get_element(&inv, 0, 0), 1.0));

    Matrix A = create(2, 2);
    set_element(&A, 0, 0, 2); set_element(&A, 0, 1, 0);
    set_element(&A, 1, 0, 0); set_element(&A, 1, 1, 2);
    destroy(&m);
    destroy(&inv);
    destroy(&A);
}
