//
// Created by mac on 11.12.2025.
//
#include "matrix.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>

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
    for (size_t i = 0; i < rows; i++)
    {
        m_data[i] = calloc(cols, sizeof(double));
        assert(m_data[i] != NULL);
    }
    assert(m_data != NULL);

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
    if (m->cols * m->rows == 0)
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


//void resize(Matrix *m, size_t rows, size_t cols)
//{
//    if (rows == 0 || cols == 0)
//    {
//        destroy(m);
//    } else
//    {
//        for
//    }
//}

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
    if (m2->cols == 1) {
        assert(is_valid(m1) && is_valid(m2));
    } else {
        assert(m1->cols == m2->cols && m1->rows == m2->rows && is_valid(m1) && is_valid(m2));
    }
    Matrix res = create(m1->rows, m1->cols);
    for (size_t i = 0; i < m1->rows; i++) {
        for (size_t j = 0; j < m1->cols; j++) {
            if (m2->cols == 1) {
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

Matrix transpose(Matrix *m)
{
    assert(is_valid(m));
    Matrix res = create(m->rows, m->cols);
    for (size_t i = 0; i < m->rows; i++)
    {
        for (size_t j = 0; j < m->cols; j++)
        {
            res.data[i][j] = m->data[j][i];
        }
    }
    return res;
}

double determinant(Matrix *m)
{
    assert(is_valid(m));

}

Matrix inverse()


