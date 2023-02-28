
#include "linear_algebra.h"

#include <stdio.h>

matrix::matrix(int n_rows, int n_cols)
  : data_(new double[n_rows * n_cols]), n_rows_(n_rows), n_cols_(n_cols)
{}

matrix::~matrix()
{
  delete[] data_;
  // The below isn't necessary, but may help make certain bugs more obvious.
  // A->data = NULL;
}

void matrix::print() const
{
  for (int i = 0; i < n_rows(); i++) {
    if (i == 0) {
      printf("{ ");
    } else {
      printf("  "); // try to keep output indented somewhat nicely
    }
    printf("{ ");
    for (int j = 0; j < n_cols(); j++) {
      printf("%g, ", (*this)(i, j));
    }
    printf("}\n");
  }
  printf("}\n");
}
