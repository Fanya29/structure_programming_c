//
// Created by mac on 11.12.2025.
//

#include "matrix_test.h"
#include "matrix.h"
#include <assert.h>
#include <math.h>
#define EPS 1e-9

static bool double_eq(double a, double b) {
    return fabs(a - b) < EPS;
}


void test_constructors(void) {
    Matrix m0 = create_empty();
    assert(!is_valid(&m0));

    Matrix v = create_vector(4);
    assert(is_valid(&v));
    assert(v.rows == 1 && v.cols == 4);
    assert(double_eq(get_element(&v, 0, 2), 0.0));

    Matrix z = create_zero(2, 3);
    assert(is_valid(&z));
    assert(z.rows == 2 && z.cols == 3);
    assert(double_eq(get_element(&z, 1, 2), 0.0));

    Matrix c = create_constants(2, 2, 7.5);
    assert(double_eq(get_element(&c, 0, 0), 7.5));
    assert(double_eq(get_element(&c, 1, 1), 7.5));

    Matrix I = create_identity(3, 3);
    assert(double_eq(get_element(&I, 0, 0), 1.0));
    assert(double_eq(get_element(&I, 0, 1), 0.0));
    assert(double_eq(get_element(&I, 2, 2), 1.0));
}

void test_element_access(void) {
    Matrix m = create(2, 2);
    set_element(&m, 0, 0, 10.0);
    set_element(&m, 1, 1, 20.0);
    assert(double_eq(get_element(&m, 0, 0), 10.0));
    assert(double_eq(get_element(&m, 1, 1), 20.0));
}

void test_set_operations(void) {
    Matrix m = create_constants(2, 2, 5.0);

    set_zero(&m);
    assert(double_eq(get_element(&m, 0, 0), 0.0));

    set_constants(&m, 100.0);
    assert(double_eq(get_element(&m, 1, 1), 100.0));

    set_identity(&m);
    assert(double_eq(get_element(&m, 0, 0), 1.0));
    assert(double_eq(get_element(&m, 1, 0), 0.0));

    destroy(&m);
}

void test_resize_operations(void) {
    Matrix m = create_constants(2, 2, 1.0);

    resize(&m, 3, 3);
    assert(m.rows == 3 && m.cols == 3);
    assert(double_eq(get_element(&m, 0, 0), 1.0));
    assert(double_eq(get_element(&m, 2, 2), 0.0));

    set_identity_resize(&m, 2, 2);
    assert(m.rows == 2 && m.cols == 2);
    assert(double_eq(get_element(&m, 1, 1), 1.0));

    set_zero_resize(&m, 1, 3);
    assert(m.rows == 1 && m.cols == 3);
    assert(double_eq(get_element(&m, 0, 2), 0.0));

    set_constants_resize(&m, 2, 2, 99.0);
    assert(double_eq(get_element(&m, 1, 1), 99.0));

    destroy(&m);
}

void test_arithmetic(void) {
    Matrix A = create_constants(2, 2, 4.0);
    Matrix B = create_constants(2, 2, 2.0);

    Matrix C = add(&A, &B);
    assert(double_eq(get_element(&C, 0, 0), 6.0));
    destroy(&C);

    C = subtract(&A, &B);
    assert(double_eq(get_element(&C, 0, 0), 2.0));
    destroy(&C);

    C = multiply_scalar(&A, 0.5);
    assert(double_eq(get_element(&C, 0, 0), 2.0));
    destroy(&C);

    C = divide_scalar(&A, 2.0);
    assert(double_eq(get_element(&C, 0, 0), 2.0));
    destroy(&C);

    destroy(&A);
    destroy(&B);
}

void test_matrix_ops(void) {
    Matrix A = create(2, 3);
    set_element(&A, 0, 0, 1); set_element(&A, 0, 1, 2); set_element(&A, 0, 2, 3);
    set_element(&A, 1, 0, 4); set_element(&A, 1, 1, 5); set_element(&A, 1, 2, 6);

    Matrix At = transpose(&A);
    assert(At.rows == 3 && At.cols == 2);
    assert(double_eq(get_element(&At, 2, 1), 6.0));

    Matrix AAt = multiply(&A, &At);
    assert(double_eq(get_element(&AAt, 0, 0), 14.0)); // 1*1 + 2*2 + 3*3 = 14
    assert(double_eq(get_element(&AAt, 1, 1), 77.0)); // 4*4 + 5*5 + 6*6 = 77

}

void test_determinant_inverse(void) {
    Matrix A = create(2, 2);
    set_element(&A, 0, 0, 2); set_element(&A, 0, 1, 1);
    set_element(&A, 1, 0, 1); set_element(&A, 1, 1, 2);

    double det = determinant(&A);
    assert(double_eq(det, 3.0));

    Matrix A_inv = inverse(&A);
    assert(double_eq(get_element(&A_inv, 0, 0), 2.0 / 3.0));
    assert(double_eq(get_element(&A_inv, 0, 1), -1.0 / 3.0));
    assert(double_eq(get_element(&A_inv, 1, 1), 2.0 / 3.0));

    Matrix I = multiply(&A, &A_inv);
    assert(double_eq(get_element(&I, 0, 0), 1.0));
    assert(double_eq(get_element(&I, 0, 1), 0.0));
    assert(double_eq(get_element(&I, 1, 1), 1.0));

    destroy(&A); destroy(&A_inv); destroy(&I);
}
