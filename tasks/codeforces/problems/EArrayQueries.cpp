#include "../../../library/common.hpp"

const int MOD = 1000000007;

class EArrayQueries {
public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    in >> N;
    VI A(N);
    for (int i = 0; i < N; ++i) {
      in >> A[i];
    }

    int K = (int)sqrt(N);
    V<VI> dp(K + 10, VI(N + 10));
    for (int k = 1; k <= K; ++k) {
      for (int p = N - 1; p >= 0; --p) {
        int np = p + A[p] + k;
        dp[k][p] = np >= N ? 1 : dp[k][np] + 1;
      }
    }

    int Q;
    in >> Q;
    for (int q = 0; q < Q; ++q) {
      int p, k;
      in >> p >> k;
      p--;
      if (k <= K) {
        out << dp[k][p] << endl;
        continue;
      }

      int cnt = 0;
      while(p < N) {
        cnt++;
        p += A[p] + k;
      }
      out << cnt << endl;
    }
  }
};
