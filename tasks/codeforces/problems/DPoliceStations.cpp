#include "../../../library/common.hpp"

const int MOD = 1000000007;


class DPoliceStations {

public:
  void solve(std::istream &in, std::ostream &out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, D;
    in >> N >> K >> D;
    V<bool> visited(N);
    queue<int> que;
    for (int i = 0; i < K; ++i) {
      int u;
      in >> u;
      u--;
      if (!visited[u]) {
        visited[u] = true;
        que.push(u);
      }
    }

    auto gDef = na2(in, N - 1, -1);
    V<V<Pii>> g(N);
    for (int i = 0; i < N - 1; ++i) {
      g[gDef._1[i]].emplace_back(gDef._2[i], i);
      g[gDef._2[i]].emplace_back(gDef._1[i], i);
    }

    V<bool> visitedEdge(N);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      debug(u);
      for (const auto &v : g[u]) {
        if (visited[v._1]) continue;
        debug("visit", v);
        visited[v._1] = true;

        visitedEdge[v._2] = true;
        que.push(v._1);
      }
    }

    Vi ans;
    for (int i = 0; i < N - 1; ++i) {
      if (!visitedEdge[i]) {
        ans.pb(i + 1);
      }
    }

    out << ans.size() << endl;
    out << join(ans) << endl;
  }
};
