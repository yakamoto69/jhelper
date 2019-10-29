#include "common.hpp"

template<typename T>
class BIT {
  const T zero = 0ll;
  inline T op(T a, T b) { return a + b; }
  
  int N;
  V<T> bit;
  
public:
  BIT(int n): N(n + 1), bit(N, zero) {}

  void add(int i, T x) {
    i++;
    while(i < N) {
      bit[i] = op(bit[i], x);
      i += i & -i;
    }
  }

  T query(int i) {
    T ans = zero;
    while(i) {
      ans = op(ans, bit[i]);
      i -= i & -i;
    }
    return ans;
  }
};