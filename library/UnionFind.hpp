#include "common.hpp"

class UnionFind {
public:
  VI p;
  VI rank;

  UnionFind(int n): p(n), rank(n, 1) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int unite(int x, int y) {
    int idx = find(x), idy = find(y);
    if (idx == idy) return idx;

    auto merge = [&](int nd, int rt) {
      rank[rt] += rank[nd];
      p[nd] = rt;
      return rt;
    };

    return rank[idx] < rank[idy] ? merge(idx, idy) : merge(idy, idx);
  }

  int find(int x) {
    return p[x] == x ? x : find(p[x]);
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }

  int count_connected(int x) {
    return rank[find(x)];
  }
};
