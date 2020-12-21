#include "common.hpp"

class SCC {
  int N;
  V<Vi> g;
  V<Vi> gi;

public:
  SCC(int n, const V<Vi> &g) : N(n), g(g), gi(N) {
    for (int u = 0; u < N; ++u) {
      for (const auto &v : g[u]) {
        gi[v].pb(u);
      }
    }
  }

  /**
   * @return (scc, sccId)
   */
  tuple<V<Vi>, Vi> build() {
    tuple<V<Vi>, Vi> res = make_tuple(V<Vi>(), Vi(N));

    Vi o2v(N);
    int ord = 0;
    V<bool> visited(N);

    function<void(int)> dfs = [&](int u) {
      visited[u] = true;
      for (const auto &v : g[u]) {
        if (visited[v]) continue;
        dfs(v);
      }
      o2v[ord++] = u;
    };

    for (int i = 0; i < N; ++i) {
      if (!visited[i]) dfs(i);
    }

    fill(all(visited), false);
    for (int o = N - 1; o >= 0; --o) {
      if (visited[o2v[o]]) continue;

      int grpId = get<0>(res).size();
      get<0>(res).pb({});
      auto &grp = get<0>(res).back();

      function<void(int)> dfs2 = [&](int u) {
        visited[u] = true;
        for (const auto &v : gi[u]) {
          if (!visited[v]) dfs2(v);
        }
        grp.pb(u);
        get<1>(res)[u] = grpId;
      };

      dfs2(o2v[o]);
    }
    return res;
  }
};