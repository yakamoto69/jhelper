#include "../../../library/common.hpp"

const int MOD = 1000000007;

class DMahmoudAndEhabAndTheBinaryString {

public:
  void solve(std::istream &in, std::ostream &out) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    in >> N;

    auto query = [&](string const &s) {
      out << "? " << s << endl;
      out.flush();
      int res;
      in >> res;
      return res;
    };

    int cnt1s = query(string(N, '0'));
    bool isFirst1 = query("1" + string(N - 1, '0')) - cnt1s == -1;
    bool isSearching1 = !isFirst1;

    debug(cnt1s, isFirst1);

    function<int(int, int)> dfs = [&](int l, int r) {
      int n = r - l;
      if (n == 1) return l;
      int nl = n/2;


      // 左半分を反転
      string queryS = string(N, '0');
      for (int i = l; i < l + nl; ++i) {
        queryS[i] = '1';
      }
      int cnt1sub0l = cnt1s - query(queryS);
      int cnt1l = (cnt1sub0l + nl) / 2;

      debug(cnt1l);

      if ((isSearching1 && cnt1l > 0)  || (!isSearching1 && nl - cnt1l > 0)) {
        return dfs(l, l + nl);
      } else {
        return dfs(l + nl, r);
      }
    };

    int found = dfs(0, N);
    if (isFirst1) {
      out << "! " << found + 1 << " " << 1 << endl;
    } else {
      out << "! " << 1 << " " << found + 1 << endl;
    }
    out.flush();
  }
};
