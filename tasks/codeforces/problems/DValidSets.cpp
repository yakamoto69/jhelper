#include "../../../library/common.hpp"

const int MOD = 1000000007;

class DValidSets {
public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, N;
    in >> D >> N;
    V<Pii> A;
    for (int u = 0; u < N; ++u) {
      int a;
      in >> a;
      A.emplace_back(a, u);
    }
    sort(all(A));
    V<Vi> g(N);
    for (int i = 0; i < N - 1; ++i) {
      int u, v;
      in >> u >> v;
      --u; --v;
      g[u].pb(v);
      g[v].pb(u);
    }

    set<int> availables;

    auto add = [&](int u) {
      availables.insert(u);
    };

    auto remove = [&](int u) {
      debug("remove",u);
      availables.erase(u);
    };

    ll ans = 0;
    function<ll(int, int)> dfs = [&](int u, int par) {
      debug("dfs", u);
      ll res = 1;
      for (const auto &v : g[u]) {
        if (v == par) continue;
        if (!availables.count(v)) continue;

        ll childRes = dfs(v, u);
        res = (res + res * childRes) % MOD;
      }
      debug(u, res);
      return res;
    };

    int l = 0;
    for (int r = 0; r < N; ++r) {
      add(A[r]._2);
      while(l < N && A[r]._1 - A[l]._1 > D) {
        remove(A[l++]._2);
      }

      ans = (ans + dfs(A[r]._2, -1)) % MOD;
    }

    out << ans << endl;
  }
};
