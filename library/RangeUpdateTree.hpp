#include "common.hpp"

template<class T>
class RangeUpdateTree {
private:
  int calcN(int x) {
    int k = 1 << (31 - __builtin_clz(x));
    return k == x ? k : k << 1;
  }

public:
  int N;
  T zero;
  function<T(T, T)> f;
  V<T> dat;

  RangeUpdateTree(int n, T zero, function<T(T, T)> f):
  N(calcN(n)), zero(zero), f(f), dat(2 * this->N, zero) {}

  /**
   * [a, b)
   */
  T query(int i) {
    int ix = i + N;
    T res = zero;
    while(ix >= 1) {
      res = f(res, dat[ix]);
      ix >>= 1;
    }
    return res;
  }

  /**
   * [a, b)
   */
  void update(int a, int b, T v) {
    int l = a + N, r = b - 1 + N;
    while(l <= r) {
      if ((l&1)) dat[l] = f(v, dat[l]);
      if (!(r&1)) dat[r] = f(v, dat[r]);
      l = (l + 1) >> 1; // 右の子供なら右の親に移動
      r = (r - 1) >> 1; // 左の子供なら左の親に移動
    }
  }
};