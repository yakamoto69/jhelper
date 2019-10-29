#include "common.hpp"

/**
 * 隣接行列使うようになっているので、隣接リストバージョンが欲しい
 */
bool topological_sort(const V<VI> &g, VI &res) {
  VI deg(g.size(), 0);
  for (auto & v : g) {
    for (int j = 0; j < v.size(); ++j) {
      if (v[j]) deg[j]++;
    }
  }

  deque<int> q;
  for (int i = 0; i < g.size(); ++i) {
    if (deg[i] == 0) q.push_back(i);
  }

  while(!q.empty()) {
    int v = q.front();
    q.pop_front();
    res.push_back(v);

    for (int u = 0; u < g[v].size(); ++u) {
      if (g[v][u]) {
        deg[u]--;
        if (deg[u] == 0) q.push_back(u);
      }
    }
  }

  bool ok = true;
  for (const auto &d : deg) ok &= d == 0;
  return ok;
}

/*
 * g: (node, cost)形式の隣接リスト
 */
ll dijkstra(const V<V<PI>> &g, int src, int dst) {
  using E = pair<ll, int>; // (cost, node)
  ll INF = (ll)1e18;
  int n = (int)g.size();
  V<ll> d(n, INF);
  priority_queue<E, V<E>, greater<PI>> q;
  q.push(E(0, src));
  d[src] = 0;

  while(!q.empty()) {
    auto e = q.top();
    q.pop();
    int v = e._2;
    ll c = e._1;

    if (d[v] == c) {
      d[v] = c;
      for (const auto &u : g[v]) {
        if (d[u._1] > c + u._2) {
          q.push(E(c + u._2, u._1));
          d[u._1] = c + u._2;
        }
      }
    }
  }

  return d[dst] == INF ? -1 : d[dst];
}

/*
 * 最大でK回遷移する
 */
int kth_bellman_ford(V<V<PI>> &g, int src, int dst, int K) {
  int INF = (int)1e9;
  int n = (int)g.size();
  V<VI> d(K + 1, VI(n, INF));
  d[0][src] = 0;
  for (int k = 0; k < K; ++k) {
    for (int v = 0; v < n; ++v) {
      for (const auto &u : g[v]) {
        d[k + 1][u._1] = min(d[k + 1][u._1], d[k][v] + u._2);
      }
    }
  }

  int res = INF;
  for (int k = 1; k <= K; ++k) res = min(res, d[k][dst]);
  return res == INF ? -1 : res;
}