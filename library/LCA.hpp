#include "common.hpp"

class LCA {
public:
  int N;
  V<VI> anc;
  VI depth;
  int K;

  LCA(V<VI> &g, int K, int rt = 0): N((int)g.size()), anc(K, VI(N)), depth(N), K(K) {
    function<void(int, int)> initParent = [&](int v, int p) {
      anc[0][v] = p;
      depth[v] = v == rt ? 0 : depth[p] + 1;
      for (const auto &u : g[v]) {
        if (p != u) initParent(u, v);
      }
    };

    initParent(rt, rt); // rtの親はrtってことにすると処理が楽になる
    for (int k = 1; k < K; ++k) {
      for (int i = 0; i < N; ++i) {
        anc[k][i] = anc[k - 1][anc[k - 1][i]];
      }
    }
  }

  int get_anc(int v, int dist) {
    int i = 0;
    while(dist > 0) {
      if (dist >> i & 1) {
        dist -= 1 << i;
        v = anc[i][v];
      }
      i++;
    }
    return v;
  }

  int operator()(int v, int u) {
    int d = min(depth[v], depth[u]);
    v = get_anc(v, depth[v] - d);
    u = get_anc(u, depth[u] - d);
    if (v == u) return v;

    function<int(int, int, int)> dfs = [&](int v, int u, int s) {
      for (int k = s; k >= 0; --k) {
        if (anc[k][u] != anc[k][v]) {
          return dfs(anc[k][u], anc[k][v], k - 1);
        }
      }
      return anc[0][v];
    };

    return dfs(v, u, K - 1);
  }
};