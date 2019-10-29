#include "common.hpp"

class PrimeFactorization {
public:
  VI prime, factor;

  PrimeFactorization(int MAX): factor(MAX + 1) {
    for (int i = 2; i <= MAX; ++i) {
      if (factor[i] == 0) {
        factor[i] = i;
        prime.push_back(i);
      }

      int p = 0;
      while (p < prime.size() && prime[p] * i <= MAX) {
        factor[prime[p] * i] = prime[p];
        if (prime[p] == i) break;
        p++;
      }
    }
  }
};