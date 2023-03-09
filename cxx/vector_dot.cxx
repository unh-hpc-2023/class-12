
#include "linear_algebra.h"

#include <assert.h>

// ----------------------------------------------------------------------
// dot
//
// returns the dot product of the two vectors
// x: first vector
// y: second vector

double dot(const vector& x, const vector& y)
{
  auto sum = xt::sum(x * y);
  return sum(0);
}
