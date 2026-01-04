//
// Created by mac on 11.12.2025.
//

#ifndef STRUCTURE_PROGRAMMING_C_MATRIX_H
#define STRUCTURE_PROGRAMMING_C_MATRIX_H

#include <string.h>
#include <stdbool.h>

typedef struct {
    size_t rows;
    size_t cols;
    double** data;
} Matrix;

Matrix create_empty();
Matrix create_vector(size_t cols);
Matrix create(size_t rows, size_t cols);
Matrix create_identity(size_t rows, size_t cols);
Matrix create_zero(size_t rows, size_t cols);
Matrix create_const(size_t rows, size_t cols, double value);
void destroy(Matrix* mat);

Matrix multiply(Matrix* mat1, Matrix* mat2);
Matrix subtract(Matrix* mat1, Matrix* mat2);
Matrix add(Matrix* mat1, Matrix* mat2);
Matrix multiply_scalar(Matrix* mat, double value);
Matrix divide_scalar(Matrix* mat, double value);

bool is_valid(Matrix* mat);
Matrix resize(Matrix* mat, size_t rows, size_t cols);

double get_element(Matrix* mat, size_t rowIdx, size_t colIdx);
void set_element(Matrix* mat, size_t rowIdx, size_t colIdx, double value);

void set_identity(Matrix* mat);
void set_zero(Matrix* mat);
void set_constants(Matrix* mat, double value);

Matrix set_identity_resize(Matrix* mat, size_t rows, size_t cols);
Matrix set_zero_resize(Matrix* mat, size_t rows, size_t cols);
Matrix set_constants_resize(Matrix* mat, size_t rows, size_t cols, double value);

Matrix transpose(Matrix* mat);
Matrix inverse(Matrix* mat);
double determinant(Matrix* mat);


#endif //STRUCTURE_PROGRAMMING_C_MATRIX_H
