
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <stdbool.h>

#include <assert.h>
#include <stdio.h>
// uncomment the following to enable bounds checking
#define BOUNDS_CHECK

// struct vector
//
// encapsulates what makes up a vector -- how many elements it contains (n),
// as well as the actual elements data[0] ... data[n-1]

struct vector
{
  double* data;
  int n;
};

#ifdef BOUNDS_CHECK
#define VEC(v, i)                                                              \
  (*({                                                                         \
    assert(i >= 0 && i < (v)->n);                                              \
    &(v)->data[i];                                                             \
  }))
#else
#define VEC(v, i) ((v)->data[i])
#endif

void vector_construct(struct vector* v, int n);
void vector_destruct(struct vector* v);
void vector_print(const struct vector* v);
bool vector_is_equal(const struct vector* x, const struct vector* y);

double vector_dot(const struct vector* x, const struct vector* y);
void vector_add(const struct vector* x, const struct vector* y,
                struct vector* z);

struct matrix
{
  double* data;
  int n_rows;
  int n_cols;
};

#ifdef BOUNDS_CHECK
#define MAT(A, i, j)                                                           \
  (*({                                                                         \
    assert(i >= 0 && i < (A)->n_rows);                                         \
    assert(j >= 0 && j < (A)->n_cols);                                         \
    &(A)->data[i * (A)->n_cols + j];                                           \
  }))
#else
#define MAT(A, i, j) ((A)->data[(i) * (A)->n_cols + (j)])
#endif

void matrix_construct(struct matrix* A, int n_rows, int n_cols);
void matrix_destruct(struct matrix* A);
void matrix_print(const struct matrix* A);

void matrix_vector_mul(const struct matrix* A, const struct vector* x,
                       struct vector* y);
void matrix_matrix_mul(const struct matrix* A, const struct matrix* B,
                       struct matrix* C);

// ----------------------------------------------------------------------

#include <stdio.h>

#define HERE                                                                   \
  fprintf(stderr, "HERE at %s:%d (%s)\n", __FILE__, __LINE__, __FUNCTION__)

#endif
