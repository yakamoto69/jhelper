#include "../../../library/common.hpp"
#include "../../../library/SegmentTree.hpp"

const int MOD = 1000000007;

class EMaximumQuestions {
public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    string S;
    in >> N >> S >> M;

    V<Vi> cumA(2, Vi(N + 1)), cumB(2, Vi(N + 1));
    for (int x = 0; x < 2; ++x) {
      for (int i = 0; i < N; ++i) {
        cumA[x][i + 1] = cumA[x][i] + (i%2 == x && S[i] == 'a' ? 1 : 0);
        cumB[x][i + 1] = cumB[x][i] + (i%2 == x && S[i] == 'b' ? 1 : 0);
      }
    }
    debug(cumA, cumB);

    auto cnt = [&](int i, int ab, int x) {
      auto &cum = ab ? cumB : cumA;
      return cum[x][i + M] - cum[x][i];
    };

    SegmentTree<Pii> tree(N + 1, pair(0, -N), [](Pii &a, Pii &b){return max(a, b);});
    tree.update(N, {0, 0});
    for (int i = N - M; i >= 0; --i) {
      int x = i % 2;
      int cntBonEven = cnt(i, 1, x);
      int cntAonOdd = cnt(i, 0, x^1);
      debug(i, cntBonEven, cntAonOdd);
      if (cntBonEven > 0 || cntAonOdd > 0) continue; // aあるべき場所にbがある、またはその逆
      auto best = tree.query(i + M, N + 1);
      int questions = M - cnt(i, 0, x) - cnt(i, 1, x^1);
      debug(best, questions);
      tree.update(i, {best._1 + 1, best._2 - questions});
    }
    int ans = -tree.query(0, N + 1)._2;
    out << ans << endl;
  }
};
