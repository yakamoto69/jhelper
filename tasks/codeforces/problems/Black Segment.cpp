#include "../../../library/common.hpp"
#include "../../../library/SegmentTree.hpp"

const int MOD = 1000000007;

class BlackSegment1244 {
public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, A, B;
    in >> N >> M >> A >> B;
    A--; B--;
    int INF = (int)1e9;
    Vi dp(N + 10, INF);
    Vi R(N + 10);
    FOR(i, M) {
      int l, r;
      in >> l >> r;
      l--; r--;
      amax(R[l], r);
      if (r >= B) {
        dp[l] = 1;
      }
    }

    for (int i = N - 1; i >= 0; --i) {
      if (R[i] == 0) continue;
      int best = dp[R[i] + 1];
      if (best != INF) {
        amin(dp[i], best + 1);
      }
    }
    debug(dp);

    int ans = INF;
    for (int i = 0; i <= A; ++i) {
      if (dp[i] != INF) amin(ans, dp[i]);
    }
    out << (ans == INF ? -1 : ans) << endl;
  }
};
