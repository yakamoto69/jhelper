#include "common.hpp"

const int MOD = 1000000007;

class CNationalProperty {
public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!solve2(in, out)) {
      out << "No" << endl;
    }
  }

  bool solve2(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    in >> N >> M;
    V<Vi> S(N);
    for (int i = 0; i < N; ++i) {
      int l;
      in >> l;
      S[i].resize(l);
      for (int j = 0; j < l; ++j) {
        int s;
        in >> s;
        --s;
        S[i][j] = s;
      }
    }

    Vi flg(M, -1);
    auto setFlg = [&](int m, int f) {
      if (flg[m] != -1 && flg[m] != f) return false;
      flg[m] = f;
      return true;
    };
    V<Vi> g(M);
    for (int i = 0; i < N - 1; ++i) {
      int n = min(S[i].size(), S[i + 1].size());
      int j = 0;
      while(j < n && S[i][j] == S[i + 1][j]) j++;
      if (j == n) {
        if (S[i].size() > S[i + 1].size()) return false;
      }
      else {
        int &c0 = S[i][j];
        int &c1 = S[i + 1][j];
        if (c0 == c1) continue;
        if (c0 > c1){
          if (!setFlg(c0, 1)) return false;
          if (!setFlg(c1, 0)) return false;
        }
        else {
          g[c1].pb(c0);
        }
      }
    }

    debug(flg, g);

    V<bool> visited(M);
    queue<int> que;
    for (int i = 0; i < M; ++i) {
      if (flg[i] == 1) que.push(i);
    }
    while(!que.empty()) {
      int u = que.front();
      que.pop();
      visited[u] = true;
      debug("visit", u);
      for (const auto &v : g[u]) {
        if (visited[v]) continue;
        if (!setFlg(v, 1)) return false;
        que.push(v);
      }
    }

    out << "Yes" << endl;
    Vi ans;
    for (int i = 0; i < M; ++i) {
      if (flg[i] == 1) ans.pb(i + 1);
    }
    out << ans.size() << endl;
    out << join(ans) << endl;

    return true;
  }
};
