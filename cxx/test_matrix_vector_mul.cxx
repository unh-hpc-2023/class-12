
#include "linear_algebra.h"

#include <assert.h>

// ----------------------------------------------------------------------
// main
//
// test the matrix_vector_mul() function

int main(int argc, char** argv)
{
  vector x{1., 2., 3.};
  // clang-format off
  matrix A{{1., 1., 0.},
           {0., 2., 0.},
           {0., 0., 3.}};
  // clang-format off
  vector y_ref = {3., 4., 9.};

  vector y = dot(A, x);
  assert(y == y_ref);

  return 0;
}
