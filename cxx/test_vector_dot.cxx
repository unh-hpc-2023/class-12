
#include "linear_algebra.h"

#include <assert.h>
#include <stdlib.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_dot() function

int main(int argc, char** argv)
{
  vector x{1., 2., 3.};
  vector y{2., 3., 4.};

  assert(dot(x, y) == 20.);

  return 0;
}
