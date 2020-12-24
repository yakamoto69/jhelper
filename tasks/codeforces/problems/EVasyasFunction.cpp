#include "../../../library/common.hpp"

const int MOD = 1000000007;

class EVasyasFunction {
public:
  void solve(std::istream &in, std::ostream &out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll X, Y;
    in >> X >> Y;

    V<pair<ll, int>> prime;
    ll x = X;
    for (ll p = 2; p*p <= X; ++p) {
      int cnt = 0;
      while (x%p == 0) {
        x /= p;
        ++cnt;
      }
      if (cnt) prime.pb({p, cnt});
    }
    if (x > 1) prime.pb({x, 1});
    debug(prime);

    int n = prime.size();
    ll ans = 0;
    ll cur = 1;
    Vi used(n);
    while(true) {
      pair best = {-1, 0ll};
      for (int i = 0; i < n; ++i) {
        if (prime[i]._2 > used[i]) {
          ll p = prime[i]._1;
          ll d = cur*p;
          ll nextY = Y - Y%d;
          if (nextY > best._2) {
            best = {i, nextY};
          }
        }
      }
      debug(best);
      if (best._1 == -1) break;

      ll nextY = best._2;
      ans += (Y - nextY) / cur;
      Y = nextY;
      cur *= prime[best._1]._1;
      used[best._1]++;
    }

    ans += Y / cur;

    out << ans << endl;
  }
};
