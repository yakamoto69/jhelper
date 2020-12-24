#include "../../../library/common.hpp"
#include "../../../library/Comb.hpp"

const int MOD = 1000000007;

class EPlusesEverywhere {
public:
  void solve(std::istream& in, std::ostream& out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    in >> N >> K;
    string digits;
    in >> digits;
    Comb comb(N, MOD);

    // 1*+*  の形
    V<ll> cum(N + 1);
    V<ll> tens(N + 1);
    tens[0] = 1;
    for (int i = 1; i < tens.size(); ++i) {
      tens[i] = tens[i - 1] * 10 % MOD;
    }
    for (int cnt = 1; cnt <= N; ++cnt) {
      int free = N - 1 - ((cnt-1) + 1); // 1*+ は数値の間cnt-1 と 固定の+分で cnt分場所が埋まる
      ll add = free >= K - 1 ? comb(free, K - 1) * tens[cnt-1] % MOD : 0;
      cum[cnt] = (cum[cnt - 1] + add)%MOD;
    }
    debug(cum);
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
      int digCnt = N - i;
      int num = digits[i] - '0';
      ans = (ans + cum[digCnt - 1]*num)%MOD; // 1+, 1*+ ...。1***は含めない

      // 1*** の形
      int free = N - 1 - (digCnt - 1); // mxDig-1 = 1***の数値の間
      if (free >= K) {
        ans = (ans + comb(free, K)*num%MOD*tens[digCnt-1])%MOD;
      }
    }
    out << ans%MOD << endl;
  }
};
