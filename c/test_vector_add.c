
#include "linear_algebra.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// ----------------------------------------------------------------------
// main
//
// test the vector_add() function

void test_vector_add(int N)
{
  struct vector x, y, z, z_ref;
  vector_construct(&x, N);
  vector_construct(&y, N);
  vector_construct(&z, N);
  vector_construct(&z_ref, N);

  for (int i = 0; i < N; i++) {
    VEC(&x, i) = 1 + i;
    VEC(&y, i) = 2 + i;
    VEC(&z_ref, i) = 3 + 2 * i;
  }

  vector_add(&x, &y, &z);
  printf("{");
   for (int i = 0; i < 4; i++) {
     printf(" %g", VEC(&z, i));
   }
   printf(" }\n");
  assert(vector_is_equal(&z, &z_ref));

  vector_destruct(&x);
  vector_destruct(&y);
  vector_destruct(&z);
  vector_destruct(&z_ref);
}

int main(int argc, char** argv)
{
  test_vector_add(3);
  test_vector_add(4);

  return 0;
}
