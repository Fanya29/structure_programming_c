//
// Created by mac on 11.12.2025.
//
#include "matrix.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

Matrix create_empty()
{
    Matrix m = {0, 0, NULL};
    return m;
}

static void initialize(Matrix *m, size_t rows, size_t cols)
{
    if (rows == 0 || cols == 0)
    {
        *m = create_empty();
    }

    double** m_data = calloc(rows, sizeof(double*));
    assert(m_data != NULL);
    for (size_t i = 0; i < rows; i++) {
        m_data[i] = calloc(cols, sizeof(double));
        if (!m_data[i]) {
            for (size_t j = 0; j < i; j++) free(m_data[j]);
            free(m_data);
            *m = create_empty();
            return;
        }
    }

    {
        m->rows = rows;
        m->cols = cols;
        m->data = m_data;
    }
}

Matrix create_vector(size_t cols)
{
    Matrix m;
    initialize(&m, 1, cols);
    return m;
}

Matrix create(size_t rows, size_t cols)
{
    Matrix m;
    initialize(&m, rows, cols);
    return m;
}

Matrix create_identity(size_t rows, size_t cols)
{
    assert(rows == cols);
    Matrix m = create(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        m.data[i][i] = 1;
    }
    return m;
}

Matrix create_zero(size_t rows, size_t cols)
{
    Matrix m = create(rows, cols);
    return m;
}

Matrix create_const(size_t rows, size_t cols, double value)
{
    Matrix m = create(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            m.data[i][j] = value;
        }
    }
    return m;
}

void destroy(Matrix *m)
{
    assert(is_valid(m) && m != NULL);
    for(size_t i = 0; i < m->rows; i++)
    {
        free(m->data[i]);
    }
    free(m->data);
    m->data = NULL;
    m->rows = 0;
    m->cols = 0;
}

bool is_valid(Matrix *m)
{
    if (m->cols == 0 || m->rows == 0 || m == NULL || m->data == NULL)
    {
        return false;
    }
    return true;
}

static double matrix_check(Matrix *m, size_t rowIdx, size_t colIdx)
{
    if(!is_valid(m) || rowIdx >= m->rows || colIdx >= m->cols)
    {
        return 0;
    } else {
        return 1;
    }
}

double get_element(Matrix *m, size_t rowIdx, size_t colIdx)
{
    assert(matrix_check(m, rowIdx, colIdx) != 0);
    return m->data[rowIdx][colIdx];
}

void set_element(Matrix *m, size_t rowIdx, size_t colIdx, double value)
{
    assert(matrix_check(m, rowIdx, colIdx) != 0);
    m->data[rowIdx][colIdx] = value;
}

void set_identity(Matrix *m)
{
    assert(m->rows == m->cols);
    for(size_t i = 0; i < m->rows; i++)
    {
        for(size_t j = 0; j < m->cols; j++)
        {
            if (i == j)
            {
                m->data[i][j] = 1;
            } else {
                m->data[i][j] = 0;
            }
        }
    }
}


void set_constants(Matrix *m, double value)
{
    for(size_t i = 0; i < m->rows; i++)
    {
        for(size_t j = 0; j < m->cols; j++)
        {
            m->data[i][j] = value;
        }
    }
}

void set_zero(Matrix *m)
{
    set_constants(m, 0);
}

void equal_mat(Matrix *m_set, Matrix *m_get)
{
    realloc(m_set, m_get->rows);
    for (size_t i = 0; i < m_get->rows; i++)
    {
        realloc(m_set->data[i], m_get->cols);
        for (size_t j = 0; j < m_get->cols; j++)
        {
            m_set->data[i][j] = m_get->data[i][j];
        }
    }
    destroy(m_get);
}

void resize(Matrix *m, size_t rows, size_t cols)
{
    assert(is_valid(m));
    if (rows == 0 || cols == 0)
    {
        destroy(m);
    } else {
        Matrix res_mat = create_zero(rows, cols);
        for (size_t i = 0; i < m->rows && i < res_mat.rows; i++)
        {
            for (size_t j = 0; j < m->cols && j < res_mat.cols; j++)
            {
                res_mat.data[i][j] = m->data[i][j];
            }
        }
        equal_mat(m, &res_mat);
    }
}

void set_identity_resize(Matrix* mat, size_t rows, size_t cols)
{
    Matrix res = create_identity(rows, cols);
    equal_mat(mat, &res);
}

void set_zero_resize(Matrix* mat, size_t rows, size_t cols)
{
    Matrix res = create_zero(rows, cols);
    equal_mat(mat, &res);
}

void set_constants_resize(Matrix* mat, size_t rows, size_t cols, double value)
{
    Matrix res = create_const(rows, cols, value);
    equal_mat(mat, &res);
}

double plus(double a, double b)
{
    return a + b;
}

double minus(double a, double b)
{
    return a - b;
}

double mult(double a, double b)
{
    return a * b;
}
double divide(double a, double b)
{
    return a / b;
}

static Matrix arif_func(Matrix *m1, Matrix *m2, double func(double a, double b))
{
    if (m2->cols == 1 && m2->rows == 1) {
        assert(is_valid(m1) && is_valid(m2));
    } else {
        assert(m1->cols == m2->cols && m1->rows == m2->rows && is_valid(m1) && is_valid(m2));
    }
    Matrix res = create(m1->rows, m1->cols);
    for (size_t i = 0; i < m1->rows; i++) {
        for (size_t j = 0; j < m1->cols; j++) {
            if (m2->cols == 1 && m2->rows == 1) {
                res.data[i][j] = func(m1->data[i][j], m2->data[0][0]);
            } else {
                res.data[i][j] = func(m1->data[i][j], m2->data[i][j]);
            }
        }
    }
    return res;
}

Matrix subtract(Matrix *m1, Matrix *m2)
{
    return arif_func(m1, m2, minus);
}

Matrix add(Matrix *m1, Matrix *m2)
{
    return arif_func(m1, m2, plus);
}

Matrix multiply_scalar(Matrix *m, double val)
{
    Matrix m2 = create_const(1, 1, val);
    return arif_func(m, &m2, mult);
}

Matrix divide_scalar(Matrix *m, double val)
{
    Matrix m2 = create_const(1, 1, val);
    return arif_func(m, &m2, divide);
}

Matrix multiply(Matrix *m1, Matrix *m2)
{
    assert(is_valid(m1) && is_valid(m2) && m1->rows == m2->cols);
    Matrix res = create(m1->rows, m2->cols);
    for (size_t i = 0; i < res.rows; i++){
        for (size_t j = 0; j < res.cols; j++){
            double val = 0;
            for (size_t k = 0; k < m1->rows; k++){
                val = val + m1->data[i][k] * m2->data[k][j];
            }
            res.data[i][j] = val;
        }
    }
    return res;
}

Matrix transpose(Matrix *m)
{
    assert(is_valid(m));
    Matrix res = create(m->cols, m->rows);
    for (size_t i = 0; i < m->rows; i++)
    {
        for (size_t j = 0; j < m->cols; j++)
        {
            res.data[j][i] = m->data[i][j];
        }
    }
    return res;
}

double determinant(Matrix *m)
{
    if (!m || !is_valid(m)|| m->rows != m->cols)
    {
        return 0;
    }
    size_t n = m->rows;
    if (n == 0) return 1.0;
    if (n == 1) return m->data[0][0];

    double **A = malloc(n * sizeof(double*));
    assert(A != NULL);
    for (size_t i = 0; i < n; i++)
    {
        A[i] = malloc(n * sizeof(double));
        if (!A[i])
        {
            for (size_t j = 0; j < i; j++) free(A[j]);
            free(A);
            return 0;
        }
        for (size_t j = 0; j < n; j++)
        {
            A[i][j] = m->data[i][j];
        }
    }

    int swaps = 0;
    for (size_t k = 0; k < n - 1; k++)
    {
        size_t pivot_row = k;
        double max_val = fabs(A[k][k]);
        for (size_t i = k + 1; i < n; i++)
        {
            double val = fabs(A[i][k]);
            if (val > max_val)
            {
                max_val = val;
                pivot_row = i;
            }
        }
        if (max_val == 0.0)
        {
            for (size_t i = 0; i < n; i++) free(A[i]);
            free(A);
            return 0.0;
        }
        if (pivot_row != k)
        {
            double *tmp = A[k];
            A[k] = A[pivot_row];
            A[pivot_row] = tmp;
            swaps++;
        }
        for (size_t i = k + 1; i < n; i++)
        {
            double factor = A[i][k] / A[k][k];
            for (size_t j = k + 1; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
        }
    }

    double det = (swaps % 2 == 0) ? 1.0 : -1.0;
    for (size_t i = 0; i < n; i++)
    {
        det *= A[i][i];
    }

    for (size_t i = 0; i < n; i++) free(A[i]);
    free(A);

    return det;
}

Matrix inverse(Matrix *m)
{
    assert(is_valid(m));
    Matrix trans = transpose(m);
    return divide_scalar(&trans, determinant(m));
}


