#include "common.hpp"

V<Vi> buildUGraph(int N, Vi &from, Vi &to) {
  V<Vi> g(N);
  for (int i = 0; i < from.size(); ++i) {
    g[from[i]].pb(to[i]);
    g[to[i]].pb(from[i]);
  }
  return g;
}

/**
 * 隣接行列使うようになっているので、隣接リストバージョンが欲しい
 */
bool topological_sort(const V<Vi> &g, Vi &res) {
  Vi deg(g.size(), 0);
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
V<ll> dijkstra(const V<V<Pii>> &g, int src) {
  using E = pair<ll, int>; // (cost, node)
  ll INF = (ll)1e18;
  int n = (int)g.size();
  V<ll> d(n, INF);
  priority_queue<E, V<E>, greater<>> q;
  q.push(E(0, src));
  d[src] = 0;

  while(!q.empty()) {
    auto visit = q.top();
    q.pop();
    int v = visit._2;
    ll c = visit._1;

    if (d[v] == c) {
      d[v] = c;
      for (const auto &e : g[v]) {
        if (d[e._1] > c + e._2) {
          q.push(E(c + e._2, e._1));
          d[e._1] = c + e._2;
        }
      }
    }
  }

  return d;
}

/*
 * 最大でK回遷移する
 */
int kth_bellman_ford(V<V<Pii>> &g, int src, int dst, int K) {
  int INF = (int)1e9;
  int n = (int)g.size();
  V<Vi> d(K + 1, Vi(n, INF));
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

bool detectCycle(int N, V<Vi> &g, int rt) {
  Vi visit(N);

  function<bool(int)> dfs = [&](int u) {
    visit[u] = 1;
    for (const auto &v : g[u]) {
      if (visit[v] == 2) continue;
      if (visit[v] == 1) return true;
      if (dfs(v)) return true;
    }
    visit[u] = 2;
    return false;
  };

  return dfs(rt);
}