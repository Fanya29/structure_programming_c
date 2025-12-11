//
// Created by mac on 11.12.2025.
//

#include "matrix_test.h"

#include "matrix.h"
#include <assert.h>
#include <stdio.h>

void test_create_empty() {
    Matrix m = create_empty();
    assert(!is_valid(&m));
    assert(m.rows == 0);
    assert(m.cols == 0);
    assert(m.data == NULL);
}

void test_create_vector() {
    Matrix m = create_vector(5);
    assert(is_valid(&m));
    assert(m.rows == 1);
    assert(m.cols == 5);
    for (size_t j = 0; j < 5; j++) {
        assert(get_element(&m, 0, j) == 0.0);
    }
    destroy(&m);
}

void test_create_identity() {
    Matrix m = create_identity(3, 3);
    assert(is_valid(&m));
    assert(m.rows == 3 && m.cols == 3);
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            double val = get_element(&m, i, j);
            assert(val == (i == j ? 1.0 : 0.0));
        }
    }
    destroy(&m);
}

void test_set_identity() {
    Matrix m = create(3, 3);
    set_constants(&m, 5.0);
    set_identity(&m);
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            double val = get_element(&m, i, j);
            assert(val == (i == j ? 1.0 : 0.0));
        }
    }
    destroy(&m);
}

void test_set_constants() {
    Matrix m = create(2, 3);
    set_constants(&m, 42.5);
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            assert(get_element(&m, i, j) == 42.5);
        }
    }
    destroy(&m);
}

void test_set_zero() {
    Matrix m = create(2, 2);
    set_constants(&m, 99.0);
    set_zero(&m);
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 2; j++) {
            assert(get_element(&m, i, j) == 0.0);
        }
    }
    destroy(&m);
}

void test_get_set_element() {
    Matrix m = create(2, 2);
    set_element(&m, 0, 0, 1.0);
    set_element(&m, 0, 1, 2.0);
    set_element(&m, 1, 0, 3.0);
    set_element(&m, 1, 1, 4.0);

    assert(get_element(&m, 0, 0) == 1.0);
    assert(get_element(&m, 1, 1) == 4.0);

    destroy(&m);
}
