#include "common.hpp"

template<class T>
class SegmentTree {
private:
  int calcN(int x) {
    int k = 1 << (31 - __builtin_clz(x));
    return k == x ? k : k << 1;
  }

  using F = function<T(T&, T&)>;

public:
  int N;
  T zero;
  F f;
  V<T> dat;

//  inline T f(T a, T b) {
//    return min(a, b);
//  }

  SegmentTree(int n, T zero, F f):
    N(calcN(n)), zero(zero), f(f), dat(2 * this->N) {
    for (auto &i : dat) {
      i = zero;
    }
  }

  void update(int i, T a) {
    int ix = i + N;
    dat[ix] = a;
    while(ix > 1) {
      int p = ix >> 1;
      dat[p] = f(dat[ix], dat[ix ^ 1]);
      ix = p;
    }
  }

  /**
   * [a, b)
   */
  T query(int a, int b) {
    auto res = zero;
    int l = a + N, r = b - 1 + N;
    while(l <= r) {
      if ((l&1)) res = f(res, dat[l]);
      if (!(r&1)) res = f(res, dat[r]);
      l = (l + 1) >> 1; // 右の子供なら右の親に移動
      r = (r - 1) >> 1; // 左の子供なら左の親に移動
    }
    return res;
  }
};