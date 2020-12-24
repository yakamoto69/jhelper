#include "../../../library/common.hpp"

const int MOD = 1000000007;

class CSadPowers {

  // sqrtの切り捨て
  ll _sqrt(ll x) {
    ll h = 1e9, l = 0;
    while(h - l > 1) {
      ll m = (h + l) / 2;
      if (m*m > x) h = m;
      else l = m;
    }
    return h - 1;
  }

  bool isPerfectSquare(ll x) {
    auto a = _sqrt(x);
    return a*a == x;
  }

public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    V<ll> cnt3; // x^p; p> 3 かつ x^2ではないもの
    for (ll a = 2; a <= 1e6 + 100; ++a) {
      ll b = a*a*a;
      while(b <= 1e18) {
        if (!isPerfectSquare(b)) cnt3.pb(b);

        if (b > 1e18/a) break;

        b *= a;
      }
    }

    debug(cnt3.size());

    sort(all(cnt3));
    cnt3.erase(unique(all(cnt3)), cnt3.end());

    auto count = [&](ll x) {
      if (x == 0) return 0ll;
      ll c2 = _sqrt(x);
      ll c3 = lower_bound(all(cnt3), x + 1) - cnt3.begin();
      debug(x, c2, c3);
      return c2 + c3;
    };

    int Q;
    in >> Q;

    for (int q = 0; q < Q; ++q) {
      ll l, r;
      in >> l >> r;
      out << count(r) - count(l - 1) << endl;
    }
  }
};
