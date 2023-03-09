
#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <cassert>
#include <vector>

#include <xtensor/xtensor.hpp>

// uncomment the following to enable bounds checking
//#define BOUNDS_CHECK

using vector = xt::xtensor<double, 1>;

double dot(const vector& x, const vector& y);

using matrix = xt::xtensor<double, 2>;

vector dot(const matrix& A, const vector& x);

#endif
