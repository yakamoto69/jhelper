#include "../../../library/common.hpp"

const int MOD = 1000000007;

class EDeskDisorder {
public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    in >> M;
    int N = 2*M;
    auto [from, to] = na2(in, M, -1);
    V<Vi> g(N);
    for (int i = 0; i < M; ++i) {
      g[from[i]].pb(to[i]);
      g[to[i]].pb(from[i]);
    }

    V<bool> visited(N);
    // (cnt, flag)
    function<pair<int, int>(int, int)> dfs = [&](int u, int par) {
      visited[u] = true;

      auto res = pair(1, 0);
      for (const auto &v : g[u]) {
        if (v == par) continue;
        if (v == u) {
          res._2 |= 2;
        }
        if (visited[v]) {
          res._2 |= 1;
          continue;
        }
        auto r = dfs(v, u);
        res._2 |= r._2;
        res._1 += r._1;
      }
      return res;
    };

    ll ans = 1l;
    for (int i = 0; i < N; ++i) {
      if (visited[i]) continue;
      auto res = dfs(i, -1);
      debug(i, res);
      if ((res._2&1) && !(res._2&2)) { // 閉路があるけど自己ループはない
        ans = ans * 2 % MOD;
      }
      else if (res._2&2) { // 自己ループがある
        ans = ans * 1 % MOD;
      }
      else if (res._1 > 1){
        ans = ans * res._1 % MOD;
      }
    }
    out << ans << endl;
  }
};
