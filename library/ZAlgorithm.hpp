#include "common.hpp"

template <typename T>
Vi zAlgorithm(V<T> &A) {
  int n = A.size();
  Vi z(n);
  for (int i = 1, j = 0; i < n; ++i) {
    int k = j + z[j] <= i ? 0 : min(j + z[j] - i, z[i - j]);
    while(i + k < n && A[k] == A[i + k]) ++k;
    z[i] = k;
    if (j + z[j] < i + z[i]) j = i;
  }
  z[0] = n;
  return z;
}