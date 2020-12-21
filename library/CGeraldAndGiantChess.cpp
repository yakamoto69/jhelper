#include "common.hpp"
#include "Comb.hpp"

const int MOD = 1000000007;

struct Point {
  int row, col;

  Point(int row, int col) : row(row), col(col) {}
};
class CGeraldAndGiantChess {
public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N;
    in >> H >> W >> N;
    H--; W--;
    V<Point> P;
    for (int i = 0; i < N; ++i) {
      int row, col;
      in >> row >> col;
      row--; col--;
      P.emplace_back(row, col);
    }

    sort(all(P), [](Point a, Point b) {
      if (a.row != b.row) return a.row < b.row;
      return a.col < b.col;
    });

    Comb comb(H + W + 100, MOD);
    V<ll> prefix(N);
    ll ans = comb(H + W, W);
    for (int i = 0; i < N; ++i) {
      prefix[i] += comb(P[i].row + P[i].col, P[i].col);
      for (int j = 0; j < i; ++j) {
        if (P[j].row <= P[i].row && P[j].col <= P[i].col) {
          int row = P[i].row - P[j].row;
          int col = P[i].col - P[j].col;
          prefix[i] = (prefix[i] + MOD - comb(row + col, col)*prefix[j]%MOD)%MOD;
        }
      }

      int rowRem = H - P[i].row;
      int colRem = W - P[i].col;
      auto remain = comb(rowRem + colRem, colRem);
      debug(i, prefix[i], remain);
      ans = (ans + MOD - prefix[i]*remain%MOD)%MOD;
    }
    debug(prefix);
    out << ans << endl;
  }
};
